#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	cin>>a>>b>>c>>d;
	char e=b[2];
	char f=d[2];
	long long g=b[0];
	long long h=b[1];
	long long shu1=d[0];
	long long shu2=d[1];
	if(b==d)
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(shu1+shu2==g+h)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if(e<='C'&&f<='C'||e>'C'&&f>'C')
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0;
		return 0;
	}
	if(shu1+shu2-1==g+h&&e==f||shu1+shu2+1==g+h&&e==f||e+1==f&&shu1==shu2||e-1==f&&shu1==shu2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
