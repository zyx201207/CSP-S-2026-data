#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel,in","r",stdin);
	freopen("travel,in","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char b2=b[2],d2=d[2];
	int b0=b[0],b1=b[1],d0=d[0],d1=d[1];
	if(a==c)
	{
		cout<<"1"; 
	}
	else
	{
		cout<<"0000";
		return 0;
	}
    if(b0==d0&&b1==d1)
    {
    	cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(b2=='A'&&d2=='B')
	{
		cout<<"1";
	}
	else if(b2=='A'&&d2=='C')
	{
		cout<<"1";
	}
	else if(b2=='B'&&d2=='C')
	{
		cout<<"1";
	}
	else if(b2=='C'&&d2=='A')
	{
		cout<<"1";
	}
	else if(b2=='C'&&d2=='B')
	{
		cout<<"1";
	}
	else if(b2=='D'&&d2=='F')
	{
		cout<<"1";
	}
	else if(b2=='F'&&d2=='D')
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	 if(b2=='A'&&d2=='B')
	{
		cout<<"1";
	}
	else if(b2=='B'&&d2=='A')
	{
		cout<<"1";
	}
	else if(b2=='B'&&d2=='C')
	{
		cout<<"1";
	}
	else if(b2=='C'&&d2=='B')
	{
		cout<<"1";
	}
	else if(b2=='F'&&d2=='D')
	{
		cout<<"1";
	}
	else if(b2=='D'&&d2=='F')
	{
		cout<<"1";
	}
	else
	{
		cout<<0;
	}
	return 0;
}
