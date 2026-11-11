#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	//1
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	//2
	if(b[0]!=d[0]||b[1]!=d[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	//3
	if(b[2]=='A')
	{
		if(d[2]!='B'&&d[2]!='C')
		{
			cout<<"00";
			return 0;
		}
	}
	if(b[2]=='B')
	{
		if(d[2]!='A'&&d[2]!='C')
		{
			cout<<"00";
			return 0;
		}
	}
	if(b[2]=='C')
	{
		if(d[2]!='B'&&d[2]!='A')
		{
			cout<<"00";
			return 0;
		}
	}
	if(b[2]=='D'&&d[2]!='F')
	{
		cout<<"00";
		return 0;
	}
	if(b[2]=='F'&&d[2]!='D')
	{
		cout<<"00";
		return 0;
	}
	cout<<"1";
	//4
	if(b[2]=='A'&&d[2]!='B')
	{
		cout<<"0";
		return 0;
	}
	if(b[2]=='C'&&d[2]!='B')
	{
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
