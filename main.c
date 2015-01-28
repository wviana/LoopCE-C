#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *arquivo;
	unsigned char value;
	unsigned char mensagem = 0;
	int bitCounter = 0;

	arquivo = fopen("testImage.bmp", "rb");

	if(!arquivo) exit(1);


	fseek(arquivo, 0x36, SEEK_SET);






	for(int i = 0; i < 500*334*3; i++){

		//Ler primeiro Byte
		fread(&value, sizeof(unsigned char), 1, arquivo);

		//Pegar bit menos significativo
		value = value & 0x01;

		//Deslocar bit para posição no byte da mensagem
		value = value << bitCounter;

		//Concatena Bit para formar Byte do Character
		mensagem = mensagem | value;

		bitCounter++;

		if(bitCounter > 7)
		{
			printf("%c", mensagem);

			bitCounter = 0;
			mensagem = 0;
			
		}

		

		
		

	}

	fclose(arquivo);




	return 0;

}

