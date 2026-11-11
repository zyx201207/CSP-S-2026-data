#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		printf("1");
	}
	else
	{
		printf("0000");
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		printf("1");
	}
	else
	{
		printf("000");
		return 0;
	}
	if(((s1[2]-'A')>=0&&(s1[2]-'A')<=2&&(s2[2]-'A')>=0&&(s2[2]-'A')<=2)||((s1[2]-'D')>=0&&(s1[2]-'D')<=1&&(s2[2]='D')>=0&&(s2[2]-'D')<=1))
	{
		printf("1");
	}
	else
	{
		printf("00");
		return 0;
	}
	if(abs((s1[2]-'A')-(s2[2]-'A'))==1)
	{
		printf("1");
	}
	else
	{
		printf("0");
		return 0;
	}
	return 0;
}
