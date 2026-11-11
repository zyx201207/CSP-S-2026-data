#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int sza=b[0]-'0'+b[1]-'0';
	int szb=d[0]-'0'+d[1]-'0';
	char zma=b[2],zmb=d[2];
	bool flag=false;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		flag=true;
		cout<<0;
	}
	if(flag)
	{
		cout<<0;
	}
	else if(sza==szb)
	{
		cout<<1;
	}
	else
	{
		flag=true;
		cout<<0;
	}
	if(flag)
	{
		cout<<0;
	}
	else if(zma>='A'&&zma<='C'&&zmb>='A'&&zmb<='C'||zma>='D'&&zma<='F'&&zmb>='D'&&zmb<='F')
	{
		cout<<1;
	}
	else
	{
		flag=true;
		cout<<0;
	}
	if(flag)
	{
		cout<<0;
	}
	else if(zma+1==zmb||zmb+1==zma)
	{
		cout<<1;
	}
	else
	{
		flag=true;
		cout<<0;
	}
	return 0;
}
