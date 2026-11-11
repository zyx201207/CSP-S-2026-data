#include <bits/stdc++.h>
using namespace std;
int flag,flag1,flag2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a==b)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='A')
	{
		if(s2[2]=='B')
		{
			cout<<"11";
			return 0;
		}
		else
		if(s2[2]=='C')
		{
			cout<<"10";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	if(s1[2]=='B')
	{
		if(s2[2]=='C'||s2[2]=='A')
		{
			cout<<"11";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	if(s1[2]=='C')
	{
		if(s2[2]=='B')
		{
			cout<<"11";
		}
		else
		if(s2[2]=='A')
		{
			cout<<"10";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	if(s1[2]=='D')
	{	
		if(s2[2]=='E')
		{
			cout<<"11";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	if(s1[2]=='E')
	{	
		if(s2[2]=='D')
		{
			cout<<"11";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(s2[2]=='A')
	{
		if(s1[2]=='B')
		{
			cout<<"11";
		}
		else
		if(s1[2]=='C')
		{
			cout<<"10";
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	if(s2[2]=='B')
	{
		if(s1[2]=='C'||s1[2]=='A')
		{
			cout<<"11";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	if(s2[2]=='C')
	{
		if(s1[2]=='B')
		{
			cout<<"11";
			return 0;
		}
		else
		if(s1[2]=='A')
		{
			cout<<"10";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	if(s2[2]=='D')
	{	
		if(s1[2]=='E')
		{
			cout<<"11";
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	if(s2[2]=='E')
	{	
		if(s1[2]=='D')
		{
			cout<<"11";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	return 0;
}
