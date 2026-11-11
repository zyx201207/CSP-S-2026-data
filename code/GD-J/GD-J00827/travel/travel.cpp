//travel

#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) printf("1");
	else
	{
		printf("0000");
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) printf("1");
	else
	{
		printf("000");
		return 0;
	}
	if(s1[2]>='D'&&s2[2]>='D'||s1[2]<'D'&&s2[2]<'D') printf("1");
	else
	{
		printf("00");
		return 0;
	}
	int a=s1[2],b=s2[2];
	if(s1[2]>='D'&&s2[2]>='D'||abs(a-b)==1) printf("1");
	else printf("0");
}
