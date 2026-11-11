#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,n,m;
	cin>>n>>a>>m>>b;
	if((n[0]!='0'&&n[1]!='1')&&(m[0]!='0'&&m[1]!='1')&&(n[0]!='1'&&n[1]!='6')&&(n[0]!='1'&&n[1]!='6')&&m==n)
	cout<<"1";
	else
	cout<<"0";
	if(a[0]==b[0]&&a[1]==b[1])
	cout<<"1";
	else
	cout<<"0";
	if((a[2]=='A'&&a[2]=='B'&&a[2]=='C'&&b[2]=='A'&&b[2]=='B'&&b[2]=='C')||(a[2]=='D'&&a[2]=='F'&&b[2]=='D'&&b[2]=='F'))
	cout<<"1";
	else
	cout<<"0";
	if(a[2]=='A'&&b[2]=='B')
	cout<<"1";
	else
	cout<<"0";
	if((a[2]=='B'&&b[2]=='A')||(a[2]=='B'&&b[2]=='C'))
	{
	cout<<"1";
	return 0;
	}
	if(a[2]=='C'&&b[2]=='B')
	{
	cout<<"1";
	return 0;
	}
	if(a[2]=='D'&&b[2]=='F')
	{
	cout<<"1";
	return 0;
	}
	if(b[2]=='A'&&a[2]=='B')
	{
	cout<<"1";
	return 0;
	}
	else
	{
	if((b[2]=='B'&&a[2]=='A')||(b[2]=='B'&&a[2]=='C'))
	cout<<"1";
	return 0;
	}
	if(b[2]=='C'&&a[2]=='B')
	{
	cout<<"1";
	return 0;
	}
	if(b[2]=='D'&&a[2]=='F')
	{
	cout<<"1";
	return 0;
	}
	else
	cout<<"0";
	}
	return 0;
}
