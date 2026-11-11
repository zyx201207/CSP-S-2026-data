#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[2],b[3],c[2],d[3];
	scanf("%s%s%s%s",&a,&b,&c,&d);
	if(c[0]==a[0]&&c[1]==a[1])
	{
		printf("1");
		if(b[0]==d[0]&&b[1]==d[1])
		{
			printf("1");
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))
			{
				printf("1");
				if((b[2]+1==d[2]&&b[2]!='C')||(d[2]+1==b[2]&&d[2]!='C'))
					printf("1");
				else
					printf("0");
			}
			else
				printf("00");
		}
		else
			printf("000");
	}
	else
		printf("0000");
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
