/*=====================================================================================================================
Keyword  : struct
File name:
Pupose   :  defind a struct with packed

=====================================================================================================================*/

typedef struct
{
	stAID	stAid;


	BYTE 	bRevertive;			// SW_REVERT, SW_NON_REVERT
	WORD 	wWtr;				// 1 ~1440
	BYTE	bShortPath;			// PORT_EAST, PORT_WEST
}__attribute__ ((packed)) stED_FFP_CMD;

// or

typedef struct
{
    #define MAX_RTRV_SW_ELEMENT	4
	BYTE 	bRepeatCnt;
	BYTE	bReserved;
	WORD	wReserved;

	stRTRV_SW_ELEMENT	astRtrvSwElement[MAX_RTRV_SW_ELEMENT]

}__attribute__ ((packed)) stRTRV_SW_RSP;
//or
typedef struct
{
	stIPC_HEADER	stIpcHeader;    /* Header 52 byte */
	unIPC_BODY		unIpcInfo;      /* Body   8000 byte */
} stIPC_FORMAT;

/*=====================================================================================================================
Keyword  :  DLD STRUCT DEFINITON
File name:
Pupose   :  defind a struct with packed

=====================================================================================================================*/
#define DLD_FILE_IS_IMAGE				( 1 )
// is this the same with #define DLD_FILE_IS_IMAGE	1. Howeover, () is used to express a function, i.e., (10/2)

/*=====================================================================================================================
Keyword  :  mq_send
File name:
Pupose   :  send to the predefined system queue

=====================================================================================================================*/

if( mq_receive(Mq_psw_main, (char *)&pstRecvMsg, MAX_QUEUE_SIZE, NULL) < 0 )
	{
		usleep( 100 );
		debug_print(DL_0,"%s-%d] psw_main msgQ recv fail(%d :%s), msg size(%d)\n",
		__FUNCTION__, __LINE__, errno, strerror(errno), sizeof(stIPC_FORMAT));
		continue;
	}

// Mq_psw_main = stSysQueue[MQID_PSW_MAIN].mqd; // checking in ini_sys_main.c
// MQID_PSW_MAIN is predefined at sysapp/inc/ipc_define.h, as follows: 
	/* 
	#define MAX_QUEUE_COUNT			( 20 )
	#define MAX_QUEUE_SIZE			( 8 )
	#define MQID_MMI_PARSER			( 1 )
	#define MQID_BKUP_MAIN			( 2 )
	#define MQID_AFM_MAIN			( 3 )
	#define MQID_AFM_INSP			( 4 )
	#define MQID_AFM_MNGE			( 5 )
	#define MQID_DLD_MAIN			( 6 )
	#define MQID_INI_MAIN			( 7 )
	#define MQID_SIPC_TX			( 8 )
	#define MQID_OAM_MAIN			( 9 )
	#define MQID_OTD_MAIN			( 10 )
	#define MQID_PFM_MAIN			( 11 )
	#define MQID_PSW_MAIN			( 12 )
	#define MQID_TMR_MAIN			( 13 )
	#define MQID_MMI_SERIAL_IN		( 14 )
	#define MQID_MMI_OUT			( 15 )
	#define MQID_ECS_SIPC_TX		( 16 )
	*/

/*=====================================================================================================================
Keyword  :  determine size of memory 
File name:
Pupose   :  
=====================================================================================================================*/
sizeof(stIPC_FORMAT)


/*=====================================================================================================================
Keyword  :  debug log to cli_out  
File name:
Pupose   :  
=====================================================================================================================*/

cli_out("%s-%d] PSW_main Start .... \n", __FUNCTION__, __LINE__);

debug_print(DL_0,"%s-%d] psw_main msgQ recv fail(%d :%s), msg size(%d)\n",
			__FUNCTION__, __LINE__, errno, strerror(errno), sizeof(stIPC_FORMAT));
			
debug_print(DL_0,"%s-%d] psw_main initialize incomplete.... \n", __FUNCTION__, __LINE__);
			
// or we can do like this 

cli_out(" ======================================================= ");
cli_out(" RNSA               | Channel ");
cli_out(" -------------------+------------------------------------ ");
cli_out(" Work  Short  Delay | CH  Slot  Addr  Value          ");
cli_out(" -------------------+------------------------------------ ");

// functions in lib_common_util.c

void cli_out(const char *format, ...)
{
	FILE	*fp;
	va_list	args;
	char	buf[LIB_LOG_BUF_MAXLEN];

	fp = fopen(LIB_LOG_CONSOLE_PATH, LIB_LOG_OPEN_RW);
	if( fp == NULL )
	{
		return;
	}

	va_start(args, format);
	vsnprintf(buf, sizeof buf, format, args);
	fprintf(fp, "%s\n", buf);
	va_end(args);

	fclose(fp);
}
// debug_print: 
void debug_print(BYTE bLevel, const char *format, ...)
{
	FILE	*fp;
	va_list	args;
	char	buf[LIB_LOG_BUF_MAXLEN];
	BYTE	bRepeat;
	pthread_t	threadId;

	threadId = pthread_self();
	if( bLevel == DL_0 )
	{
		goto out_print;
	}
	else
	{
		if( gbDebugPrintFlag == SYS_TRUE )
		{
			for( bRepeat = MMI_PARSER_THREAD_ID; bRepeat <= THREAD_MAX_ID; bRepeat++ )
			{
				if( (gaThreadId[bRepeat] == threadId) && (gabDebugPrintLevel[bRepeat] == bLevel) )
				{
					goto out_print;
				}
				else
				{
					continue;
				}
			}
			return;
		}
		else
		{
			return;
		}
	}

out_print:
	fp = fopen(LIB_LOG_CONSOLE_PATH, LIB_LOG_OPEN_RW);
	if( fp == NULL )
	{
		return;
	}
	va_start(args, format);
	vsnprintf(buf, sizeof buf, format, args);
	fprintf(fp, "%s\n", buf);
	va_end(args);

	fclose(fp);
		
	syslog(LOG_INFO,"%s\n", buf);
}


/*=====================================================================================================================
Keyword  :  condition in C: switch, for, if 
File name:
Pupose   :  
=====================================================================================================================*/
switch( wFunctionCode )
	{
		case TMR_100MS	: 
			dwPollCnt++;
			psw_poll_proc(dwPollCnt);
			break;
		case TMR_1S		:
			//psw_poll_proc(1);
			break;
		default			: psw_cmd_proc(pstRecvMsg);	break;
	}

if(bSlot <= SLOT_S20)
{
	// expression here
}
for(bSlot = SLOT_S1; bSlot <= SLOT_S20; bSlot++)
{
	// expression here
}

// or

(bCurrWork == PORT_EAST) ? (bNextWork = PORT_WEST) : (bNextWork = PORT_EAST);



/*=====================================================================================================================
Keyword  :  lib_common_response_send_to_thread
File name:
Pupose   :  to send pstIpcMsg information to mmi_out
=====================================================================================================================*/
lib_common_response_send_to_thread( pstIpcMsg, Mq_mmi_out, dwMessageLength, COMMAND_OK, (void *)&stResponse );


/*=====================================================================================================================
Keyword  :  pointer
File name:
Pupose   :  khai bao con tro 
=====================================================================================================================*/

stIPC_FORMAT	*pstRecvMsg;



/*=====================================================================================================================
Keyword  :  pointer
File name:
Pupose   :  su dung con tro: variable and function 
=====================================================================================================================*/

mq_receive(Mq_psw_main, (char *)&pstRecvMsg, MAX_QUEUE_SIZE, NULL) 

// pointer as a struct 

stAID			*pstAid = &(pstIpcMsg->stIpcHeader.stInfoHeader.stAid);

pstElement = (stRTRV_SW_DISTANCE_ELEMENT *)&pstRspMsg->astElement[0][0];





/*=====================================================================================================================
Keyword  :  memory usage of variable types 
File name:
Pupose   :  su dung con tro: variable and function 
=====================================================================================================================*/
// websites to study:  
https://www.usna.edu/Users/cs/aviv/classes/ic221/s16/lec/08/lec.html
https://www.tutorialspoint.com/cprogramming/c_data_types.htm
https://www.tutorialspoint.com/cprogramming/c_data_types.htm


int : integer number : 4-bytes
short : integer number : 2-bytes
long : integer number : 8-bytes
char : character : 1-byte
float : floating point number : 4-bytes
double : floating point number : 8-bytes
void * : pointers : 8-bytes on (64 bit machines)

// Integer Types

// Type	            Storage size	Value range
char	            1 byte	       	-128 to 127 or 0 to 255
unsigned char		1 byte			0 to 255
signed char			1 byte			-128 to 127
int					2 or 4 bytes	-32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
unsigned int		2 or 4 bytes	0 to 65,535 or 0 to 4,294,967,295
short				2 bytes			-32,768 to 32,767
unsigned short		2 bytes			0 to 65,535
long				4 bytes			-2,147,483,648 to 2,147,483,647
unsigned long		4 bytes			0 to 4,294,967,295

// To get the exact size of a type or a variable on a particular platform, you can use the sizeof operator. The expressions sizeof(type) yields the storage size of the object or type in bytes. Given below is an example to get the size of int type on any machine −

// Live Demo
#include <stdio.h>
#include <limits.h>

int main() {
   printf("Storage size for int : %d \n", sizeof(int));
   
   return 0;
}
// When you compile and execute the above program, it produces the following result on Linux−Storage size for int : 4

// Floating-Point Types

// The following table provide the details of standard floating-point types with storage sizes and value ranges and their precision −

// Type	Storage size		Value range						Precision
float		4 byte			1.2E-38 to 3.4E+38	6 			decimal places
double		8 byte			2.3E-308 to 1.7E+308	15 		decimal places
long double	10 byte			3.4E-4932 to 1.1E+4932	19 		decimal places

// The header file float.h defines macros that allow you to use these values and other details about the binary representation of real numbers in your programs. The following example prints the storage space taken by a float type and its range values −

// Live Demo
#include <stdio.h>
#include <float.h>

int main() {
   printf("Storage size for float : %d \n", sizeof(float));
   printf("Minimum float positive value: %E\n", FLT_MIN );
   printf("Maximum float positive value: %E\n", FLT_MAX );
   printf("Precision value: %d\n", FLT_DIG );
   
   return 0;
}
// Output: 
Storage size for float : 4
Minimum float positive value: 1.175494E-38
Maximum float positive value: 3.402823E+38
Precision value: 6

The void type specifies that no value is available. It is used in three kinds of situations −

1 Function returns as void

There are various functions in C which do not return any value or you can say they return void. A function with no return value has the return type as void. For example, void exit (int status);

2 Function arguments as void

There are various functions in C which do not accept any parameter. A function with no parameter can accept a void. For example, int rand(void);

3 Pointers to void

A pointer of type void * represents the address of an object, but not its type. 

For example, a memory allocation function void *malloc( size_t size ); returns a pointer to void which can be casted to any data type.



/*=====================================================================================================================
Keyword  :  memset
File name:
Pupose   :  
=====================================================================================================================*/
memset( (void *)&stResponse, 0x00, dwMessageLength

// Following is the declaration for memset() function.

void *memset(void *str, int c, size_t n)

// str − This is a pointer to the block of memory to fill.

// c − This is the value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.

// n − This is the number of bytes to be set to the value.

// Return Value: This function returns a pointer to the memory area str.

Example

#include <stdio.h>
#include <string.h>

int main () {
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   memset(str,'$',7); // value to be set. 
   puts(str);
   
   return(0);
}
Let us compile and run the above program that will produce the following result −

This is string.h library function
$$$$$$$ string.h library function

/*=====================================================================================================================
Keyword  :  memcpy
File name:
Pupose   :  
=====================================================================================================================*/
memcpy((void *)&(stResponse.astRtrvSwElement[j].stAid), pstAid, sizeof(stAID));
(bWorking == PORT_EAST+j)
				 ? (stResponse.astRtrvSwElement[stResponse.bRepeatCnt].bSwState	= WORKING)
				 : (stResponse.astRtrvSwElement[stResponse.bRepeatCnt].bSwState	= STAND_BY);




/*=====================================================================================================================
Keyword  :  tele_free 
File name:
Pupose   :  
=====================================================================================================================*/

void tele_free( BYTE *bptr )
{
	if( bptr != NULL )
	{
		free( (void *)bptr );
		bptr = NULL;
	}
}



/*=====================================================================================================================
Keyword  :  void free(void *ptr)
File name:
Pupose   :  deallocates the memory previously allocated by a call to calloc, malloc, or realloc.
Description: ptr − This is the pointer to a memory block previously allocated with malloc, calloc or realloc to be deallocated. If a null pointer is passed as argument, no action occurs.

=====================================================================================================================*/

// 

// The following example shows the usage of free() function.

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char *str;

   /* Initial memory allocation */
   str = (char *) malloc(15);
   strcpy(str, "tutorialspoint");
   printf("String = %s,  Address = %u\n", str, str);

   /* Reallocating memory */
   str = (char *) realloc(str, 25);
   strcat(str, ".com");
   printf("String = %s,  Address = %u\n", str, str);

   /* Deallocate allocated memory */
   free(str);
   
   return(0);
}
// Let us compile and run the above program that will produce the following result −

String = tutorialspoint, Address = 355090448
String = tutorialspoint.com, Address = 355090448




/*=====================================================================================================================
Keyword  :  tele_free 
File name:
Pupose   :  
=====================================================================================================================*/

void bzero(void *s, size_t n); 
The bzero() function shall place n zero-valued bytes in the area pointed to by s.

The memset() function is preferred over this function.

For maximum portability, it is recommended to replace the function call to bzero() as follows:

#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)



/*=====================================================================================================================
Keyword  :  usleep(n) 
File name: 
Pupose   :  execution of the calling thread for (at least) usec microseconds.
Description: The type useconds_t is an unsigned integer type capable of holding
       integers in the range [0,1000000].

=====================================================================================================================*/
// checking;

#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main( int argc, char ** argv )
{

        const unsigned long long nano = 1000000000;
        unsigned long long t1, t2;

        struct timespec tm;

        for(;;)
        {

                clock_gettime( CLOCK_REALTIME, &tm );
                t1 = tm.tv_nsec + tm.tv_sec * nano;

                usleep( 20000 );

                clock_gettime( CLOCK_REALTIME, &tm );
                t2 = tm.tv_nsec + tm.tv_sec * nano;

                printf( "delay: %ld\n", ( t2 - t1 ) / 1000 );
        }

        return 0;

}
And the result of it's running:

$ ./a.out
delay: 29233
delay: 29575
delay: 29621
delay: 29694
delay: 29688
delay: 29732
delay: 29709
delay: 29706
delay: 29666
delay: 29702
delay: 29702
delay: 29705
delay: 29789
delay: 29619
delay: 29785
delay: 29634
delay: 29692
delay: 29708
delay: 29701
delay: 29703
