#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y;
	string s1,s2;
	cin>>x>>s1>>y>>s2;
	if(x==y)cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(int(s1[0]-'0')+int(s1[1]-'0')==int(s2[0]-'0')+int(s2[1]-'0'))
		cout<<1;
	else 
	{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
			cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(s1[2]=='D'||s1[2]=='F')
	{
		if(s2[2]=='D'||s2[2]=='F')
			cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(s1[2]=='D'||s2[2]=='D')
	{
		cout<<1;
		return 0;
	}
	if(s1[2]=='A')
	{
		if(s2[2]=='B')
			cout<<1;
		else cout<<0;
		return 0;
	}
	if(s1[2]=='B')
	{
		if(s2[2]=='A')
			cout<<1;
		else if(s2[2]=='C')
			cout<<1;
		else cout<<0;
		return 0;
	}
	if(s1[2]=='C')
	{
		if(s2[2]=='B')
			cout<<1;
		else cout<<0;
		return 0;
	}
	return 0;
}
