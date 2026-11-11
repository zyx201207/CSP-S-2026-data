#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int a,b;
string x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	else 
	{
		cout<<"1";
		if(x[0]==y[0] && x[1]==y[1])
			cout<<"1";
		else{
			cout<<"000";
			return 0;
		}
	}
	if(x[2]>='A' && x[2]<='C')
	{
		if(y[2]>='A'&&y[2]<='C')
		{
			cout<<"1";
			if(x[2]=='A' && y[2]=='C')
				cout<<"0";
			else
				cout<<"1";
		}
		else
			cout<<"00";
	}
	else
	{
		if(y[2]>='D' && y[2]<='F')
			cout<<"1";
		else
			cout<<"0";
	}
	return 0;
}
