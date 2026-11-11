#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	string s1,s2;
	cin>>a1>>s1>>b1>>s2;
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)!=s2.substr(0,2))
	{
		cout<<"1000";
		return 0;
	}
	if(s1[2]=='A')
	{
		if(s2[2]=='B')
		{
			cout<<"1111";
			return 0;
		}
		if(s2[2]=='C')
		{
			cout<<"1110";
			return 0;
		}
		cout<<"1100";
		return 0;
	}
	if(s1[2]=='B')
	{
		if(s2[2]=='A')
		{
			cout<<"1111";
			return 0;
		}
		if(s2[2]=='C')
		{
			cout<<"1111";
			return 0;
		}
		cout<<"1100";
		return 0;
	}
	if(s1[2]=='C')
	{
		if(s2[2]=='B')
		{
			cout<<"1111";
			return 0;
		}
		if(s2[2]=='A')
		{
			cout<<"1110";
			return 0;
		}
		cout<<"1100";
		return 0;
	}
	if(s1[2]=='D')
	{
		if(s2[2]=='F')
		{
			cout<<"1111";
			return 0;
		}
		cout<<"1100";
		return 0;
	}
	if(s1[2]=='F')
	{
		if(s2[2]=='D')
		{
			cout<<"1111";
			return 0;
		}
		cout<<"1100";
		return 0;
	}
	return 0;
}
