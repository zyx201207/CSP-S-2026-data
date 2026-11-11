#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,a,b,c,d,e;
	cin>>s>>a>>b>>c;
	if(s==b)
	{
		cout<<'1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	d=a.substr(0,2);
	e=c.substr(0,2);
	if(d==e)
	{
		cout<<'1';
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(a[2]<'D'&&c[2]<'D'||a[2]>'C'&&c[2]>'C')
	{
		cout<<'1';
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(a[2]-c[2])==1||a[2]=='d'&&c[2]=='f'||a[2]=='f'&&c[2]=='d')
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
}
