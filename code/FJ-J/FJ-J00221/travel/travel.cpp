#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
		{x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=7;
char ca[7],cb[7],sa[7],sb[7];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i,j;
	scanf("%s%s%s%s",ca,sa,cb,sb);
	if(10*(ca[0]-'0')+ca[1]-'0'==
		10*(cb[0]-'0')+cb[1]-'0')
		printf("1");
	else
	{
		printf("0000");
		return 0;
	}
	if(10*(sa[0]-'0')+sa[1]-'0'==
		10*(sb[0]-'0')+sb[1]-'0')
			printf("1");
	else
	{
		printf("000");
		return 0;
	}
	if((sa[2]=='A'||sa[2]=='B'||sa[2]=='C')&&
		(sb[2]=='A'||sb[2]=='B'||sb[2]=='C'))
		printf("1");
	else if((sa[2]=='D'||sa[2]=='F')&&
		(sb[2]=='D'||sb[2]=='F'))
		printf("1");
	else
	{
		printf("00");
		return 0;
	}
	if((sa[2]=='A'||sa[2]=='C')&&
		(sb[2]=='A'||sb[2]=='C'))
		printf("0");
	else printf("1");
	return 0;
}
