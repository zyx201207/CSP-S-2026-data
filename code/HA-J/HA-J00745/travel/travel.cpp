#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool ok,ok1,ok2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		ok=1;
	}
	else
	{
		cout<<0;
		ok=0;
	}
	if(b[0]==d[0]&&b[1]==d[1])
	{
		cout<<1;
		ok1=1;
	}
	else
	{
		cout<<0;
		ok1=0;
	}
	if(ok1&&((b[2]<'D'&&d[2]<'D')||(b[2]>'C'&&d[2]>'C')))
	{
		cout<<1;
		ok2=1;
	}
	else
	{
		cout<<0;
		ok2=0;
	}
	if(ok&&ok2&&abs(b[2]-d[2])==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
