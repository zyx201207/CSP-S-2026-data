#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if(s1[2]-0<=67&&s2[2]-0<=67)
	{
		cout<<1;
	}
	else if(s1[2]-0>=68&&s2[2]-0>=68)
	{
		cout<<1<<1;
		return 0; 
	}
	else
	{
		cout<<0<<0;
		return 0;
	}
	int l=max(s1[2]-0,s2[2]-0),r=min(s1[2]-0,s2[2]-0);
	if(l-r==1)
	{
		cout<<1;
	} 
	else
	{
		cout<<0;
	}
	return 0;
}
