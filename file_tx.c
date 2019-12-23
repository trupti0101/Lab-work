#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"


main()
{
	char filename[15],buf;
  	int i=0,
   	cport_nr=0,        /* /dev/ttyS0 (COM1 on windows) */
      bdrate=9600;       /* 9600 baud */

	FILE *in;
  char mode[]={'8','N','1',0},
       str[2][512];


  if(RS232_OpenComport(cport_nr, bdrate, mode))
  {
    printf("Can not open comport\n");

  }
  
  printf("Enter the filename to be created:");
      scanf("%s",filename);
	in=fopen(filename,"rt");
      printf("\n\nsending.....\n\n");
      while(1)
      {
       buf=fgetc(in);
       printf("%c",buf);
       RS232_SendByte(cport_nr,buf);
       printf("sent: %s\n", str[i]);

	#ifdef _WIN32
	    Sleep(1000);
	#else
	    usleep(1000000);  /* sleep for 1 Second */
	#endif
	
}

}


