#include<bits/stdc++.h>
using namespace std;
char a[2],a1[3],b[2],b1[3],x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	for(int i=0;i<2;i++)
		scanf("%c",&a[i]);
	scanf("%c",&x);
	for(int i=0;i<3;i++)
		scanf("%c",&a1[i]);
	scanf("%c",&x);
	for(int i=0;i<2;i++)
		scanf("%c",&b[i]);
	scanf("%c",&x);
	for(int i=0;i<3;i++)
		scanf("%c",&b1[i]);
	if(a[0]==b[0]&&a[1]==b[1])
	{
		printf("1");
		if(a1[0]==b1[0]&&a1[1]==b1[1])
		{
			printf("1");
			if(a1[2]<='C'&&b1[2]<='C'||a1[2]>'C'&&b1[2]>'C')
			{
				printf("1");
				if(a1[2]-b1[2]==1||b1[2]-a1[2]==1)
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
	return 0;
}
