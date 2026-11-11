#include<bits/stdc++.h>
using namespace std;
int che1,che2,pai1,pai2,lie1,lie2;
char a,b,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&che1);
	scanf("%c",&a);
	scanf("%c%c%c",&a,&b,&c);
	pai1=(a-'0')*10+b-'0';
	lie1=c-'A'+1;
	scanf("%d",&che2);
	scanf("%c",&a);
	scanf("%c%c%c",&a,&b,&c);
	pai2=(a-'0')*10+b-'0';
	lie2=c-'A'+1;
	if(che1==che2)
	{
		printf("1");
	}
	else
	{
		printf("0000");
		return 0;
	}
	if(pai1==pai2)
	{
		printf("1");
	}
	else
	{
		printf("000");
		return 0;
	}
	if((lie1<=3&&lie2<=3)||(lie1>=4&&lie2>=4))
	{
		printf("1");
	}
	else
	{
		printf("00");
		return 0;
	}
	if(((lie1-lie2)==1)||((lie2-lie1)==1))
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	return 0;
}
//BY itzrealyou
