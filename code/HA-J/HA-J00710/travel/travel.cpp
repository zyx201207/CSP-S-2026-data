#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,ans;
bool b=true;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		ans+='0';
		printf("0000");
		return 0;
	}
	else
		ans+='1';
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		ans+='1';
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='B'&&s2[2]=='A'))
		{
			printf("1111");
			return 0;
		}
		else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
		{
			printf("1110");
			return 0; 
		}
		else if((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D'))
		{
			printf("1100");
			return 0; 
		}
	}
	else
	{
		printf("1000");
		return 0;
	}
	return 0;
}
