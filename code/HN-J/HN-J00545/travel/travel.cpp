#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		printf("0000");
		return 0;
	}
	else
	{
		printf("1");
		if(s1[1]!=s2[1])
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
		if((s1[1]==s2[1])&&((s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')||(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		if((s1[1]==s2[1])&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
