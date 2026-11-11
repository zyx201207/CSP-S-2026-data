#include<bits/stdc++.h>
using namespace std;
int as,ab,bs,bb;
char al,bl;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&as,&ab,&al,&bs,&bb,&bl);
	if(as==bs)
	{
		if(ab==bb)
		{
			if(((al=='D'||al=='F')&&(bl=='F'||bl=='D'))||((al=='A'||al=='B'||al=='C')&&(bl=='A'||bl=='B'||bl=='C')))
			{
				if((al=='D'&&bl=='F')||(al=='F'&&bl=='D')||(al=='A'&&bl=='B')||(al=='B'&&bl=='C')||(al=='B'&&bl=='A')||(al=='C'&&bl=='B'))
				{
					printf("1111");
				}
				else
				{
					printf("1110");
				}
			}
			else
			{
				printf("1100");
			}
		}
		else
		{
			printf("1000");
		}
	}
	else
	{
		printf("0000");
	}
	return 0;
}
