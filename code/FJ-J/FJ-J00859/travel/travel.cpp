#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//是否在同一节车厢 
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	//是否在同一行 
	if(s1[0]+s1[1]==s2[0]+s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	//是否在同一行同一侧 
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		{
			cout<<1;
		}
		else
		{
			cout<<0<<0;
			return 0;
		}
	}
	else
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<1;
		}
		else
		{
			cout<<0<<0;
			return 0;
		}
	}
	//是否在同一行并相邻
	if(s1[2]=='A')
	{
		if(s2[2]=='B')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(s1[2]=='B')
	{
		if(s2[2]=='A'||s2[2]=='C')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(s1[2]=='C')
	{
		if(s2[2]=='B')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(s1[2]=='D')
	{
		if(s2[2]=='F')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		if(s2[2]=='D')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
}
