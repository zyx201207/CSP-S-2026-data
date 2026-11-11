#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	char a1[3],a2[3],b1[4],b2[4];
	scanf("%s %s %s %s",a1,a2,b1,b2);
	if(!strcmp(a1,b1))
	{
		printf("1");
		if(a2[0]==b2[0] && a2[1]==b2[1])
		{
			printf("1");
			if((a2[2]>='A' && a2[2]<='C') && (b2[2]>='A' && b2[2]<='C'))
			{
				printf("1");
				if(a2[2]=='A' && b2[2]=='B') printf("1");
				else if(a2[2]=='B' && (b2[2]=='A' || b2[2]=='C')) printf("1");
				else printf("0");
			}
			else if((a2[2]>='D' && a2[2]<='F') && (b2[2]>='D' && b2[2]<='F'))
			{
				printf("1");
				if(a2[2]=='D' && b2[2]=='F') printf("1");
				else if(a2[2]=='F' && b2[2]=='D') printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
		}
	else printf("0000");
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
