#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	n=(a[0]-'0')*10+(a[1]-'0');
	m=(c[0]-'0')*10+(c[1]-'0');
	if(n==m)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if((b[1]-'0')==(d[1]-'0'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-d[2])==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
