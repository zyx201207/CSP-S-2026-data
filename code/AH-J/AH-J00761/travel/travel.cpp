#include <bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	cin>>s1;
	cin>>m;
	cin>>s2;
	if(n!=m) 
	{
		cout<<"0000";
		return 0;
	}
	else cout<<'1';
	if(s1[2]==s2[2]) 
	{
		cout<<"000";
		return 0;
	}	
	if(s1[0]==s2[0] && s1[1]==s2[1])
	{
		cout<<'1';
	}
	else 
	{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='F') 
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
	if(s1[2]=='D') 
	{
		if(s2[2]=='F')
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
	if(s1[2]=='A')
	{
		if(s2[2]=='B')
		{
			cout<<"11";
			return 0;
		}
		if(s2[2]=='C')
		{
			cout<<"10";
			return 0;
		}
	}
	if(s1[2]=='B')
	{
		if(s2[2]=='C' || s2[2]=='A')
		{
			cout<<"11";
			return 0;
		}
	}
	if(s1[2]=='C')
	{
		if(s2[2]=='B')
		{
			cout<<"11";
			return 0;
		}
		if(s2[2]=='A')
		{
			cout<<"10";
			return 0;
		}
	}
	cout<<"00";
	return 0;
}
