#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int n,m,a=0;
string x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>x>>m>>y;
	if(n==m) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(x[0]==y[0] && x[1]==y[1]) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if(x[2]<='C' && y[2]<='C')
	{
		cout<<"1";
		a=1;
	}
	else if(x[2]>='D' && y[2]>='D')
	{
		cout<<"1";
		a=1;
	}
	if(a!=1)
	{
		cout<<"00";
		return 0;
	}
	if(x[2]%2==1 && y[2]%2==0)
	{
		if(a!=1) cout<<"0";
		cout<<"1";
		return 0;
	}
	else if(x[2]%2==0 && y[2]%2==1)
	{
		if(a!=1) cout<<"0";
		cout<<"1";
		return 0;
	}
	if(a!=1) cout<<"0";
	cout<<"0";
	return 0;
}
