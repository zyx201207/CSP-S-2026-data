#include <bits/stdc++.h>
using namespace std;
int a1,a2,b1[2],b2[2];
string c1,c2;
char u,v;
void all()
{
	if(u=='A')
	{
		if(v=='B')
		{
			cout<<1;
			return;
		}
	}
	else if(u=='B')
	{
		if(v=='A' || v=='C')
		{
			cout<<1;
			return;
		}
	}
	else if(u=='C')
	{
		if(v=='B')
		{
			cout<<1;
			return;
		}
	}
	else if(u=='D')
	{
		if(v=='F')
		{
			cout<<1;
			return;
		}
	}
	else
	{
		if(v=='D')
		{
			cout<<1;
			return;
		}
	}
	cout<<0;
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>a1>>c1>>a2>>c2;
	if(a1==a2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	b1[0]=c1[0],b1[1]=c1[1],b2[0]=c2[0],b2[1]=c2[1],u=c1[2],v=c2[2];
	if(b1[0]==b2[0] && b1[1]==b2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(((u=='A'||u=='B'||u=='C')&&(v=='A'||v=='B'||v=='C'))||((u=='D'||u=='F')&&(v=='D'||v=='F')))
	{
		cout<<1;
		all();
	}
	else
	{
		cout<<"00";
	}
	return 0;
}
