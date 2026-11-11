#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else if(c1!=c2)
	{
		cout<<0;
	}
	if(s1[0]+s1[1]==s2[0]+s2[1])
	{
		cout<<1;
	}
	else if(s1[0]+s1[1]!=s2[0]+s2[1])
	{
		cout<<0;
	}
	if(s1[3]=='D'||s1[3]!='E')
	{
		if(s2[3]=='D'||s2[3]!='E')
	{
		cout<<0;
	}
	}
	else
	{
		cout<<1;
	}
	if(s1[3]==s2[3]+1&&s2[3]==s1[3]+1)
	{
		if(s1[3]!='D'||s2[3]!='D')
		{
			cout<<1;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}

