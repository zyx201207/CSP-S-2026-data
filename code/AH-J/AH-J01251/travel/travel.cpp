#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
long long x,y;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2)
	{
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	x=(b1[0]-'0')*10+(b1[1]-'0');
	y=(b2[0]-'0')*10+(b2[1]-'0');
	if(x==y)
	{
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(b1[2]=='F'&&b2[2]=='D')
	{
		cout<<1<<1;
	}else if(b1[2]=='D'&&b2[2]=='F')
	{
		cout<<1<<1;
	}else if(b1[2]=='A'&&b2[2]=='B')
	{
		cout<<1<<1;
	}else if(b1[2]=='A'&&b2[2]=='C')
	{
		cout<<1<<0;
	}else if(b1[2]=='B'&&b2[2]=='C')
	{
		cout<<1<<1;
	}else if(b1[2]=='B'&&b2[2]=='A')
	{
		cout<<1<<1;
	}else if(b1[2]=='C'&&b2[2]=='A')
	{
		cout<<1<<0;
	}else if(b1[2]=='C'&&b2[2]=='B')
	{
		cout<<1<<1;
	}else{
		cout<<0<<0;
	}
	return 0;
}
