#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[3];
	char b[3];
	scanf("%d%d%c",&a[0],&a[1],&a[2]);
	scanf("%d%d%c",&b[0],&b[1],&b[2]);
	if(a[0]==b[0])
	{
		printf("1");
		if(a[1]==b[1])
		{
			printf("1");
			if((a[2]<='C')==(b[2]<='C'))
			{
				printf("1");
				if((a[2]>='D'&&b[2]>='D')||(a[2]!='A'&&b[2]!='A')||(a[2]!='C'&&b[2]!='C'))
				{
					printf("1");
				}
				else
				{
					printf("0");
				} 
			}
			else
			{
				printf("00");
			}
		}
		else
		{
			printf("000");
		}
	}
	else
	{
		printf("0000");
	}
	return 0;
}
