#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	int x=(b1[0]-'0')*10+b1[1]-'0';
	int y=(b2[0]-'0')*10+b2[1]-'0';
	char i=b1[2];
	char j=b2[2];
	if(a1==a2)
	{
		cout<<1;
	}
	else
	{
		return cout<<"0000",0;
	}
	if(a1==a2&&x==y)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a1==a2&&x==y)
	{
		if(((i=='A'||i=='B'||i=='C')&&(j=='A'||j=='B'||j=='C'))||((i=='F'||i=='D')&&(j=='F'||i=='D')))
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
		cout<<0;
	}
	if(a1==a2&&x==y&&abs((i-'0')-(j-'0'))==1)
	{
		if(i=='C'&&j=='D'||i=='D'&&j=='C')
		{
			cout<<0;
		}
		else
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
