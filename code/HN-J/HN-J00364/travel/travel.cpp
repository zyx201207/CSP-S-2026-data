#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1,s1,c2,s2);
	int e=0;
	for(int i=0;i<=1;i++)
	{
		if(c1[i]!=c2[i])
		{
			printf("0000");
			return 0;
		}
		if(c1[i]==c2[i]&&e==1)
		{
			printf("1");
			break;
		}
		if(c1[i]==c2[i])
		{
			e=1;
		}
	}
	int e2=0;
	for(int i=0;i<=1;i++)
	{
		if(s1[i]!=s2[i])
		{
			printf("000");
			return 0;
		}
		if(s1[i]==s2[i]&&e2==1)
		{
			printf("1");
			break;
		}
		if(s1[i]==s2[i])
		{
			e2=1;
		}
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		{
			printf("1");
		}
		else if(s2[2]=='D'||s2[2]=='F')
		{
			printf("00");
			return 0;
		}
	}
	if(s1[2]=='D'||s1[2]=='F')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			printf("1");
		}
		else if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		{
			printf("00");
			return 0;
		}
	}
	if(s1[2]=='A'&&s2[2]=='B')
	{
		printf("1");
	}
	else if(s1[2]=='B'&&s2[2]=='C')
	{
		printf("1");
	}
	else if(s1[2]=='D'&&s2[2]=='F')
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
