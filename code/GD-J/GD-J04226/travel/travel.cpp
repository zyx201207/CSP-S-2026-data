#include <bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&c1,&s1,&c2,&s2);
	if(strcmp(c1,c2)==0)
		printf("1");
	else
	{
		printf("0000\n");
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		printf("1");
	else
	{
		printf("000\n");
		return 0;
	}
	if(s1[2]=='F')
		s1[2]='E';
	if(s2[2]=='F')
		s2[2]='E';
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')
	{
		printf("1");
	}
	else
	{
		printf("00\n");
		return 0;
	}
	if(s2[2]-s1[2]==1||s2[2]-s1[2]==-1)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}

