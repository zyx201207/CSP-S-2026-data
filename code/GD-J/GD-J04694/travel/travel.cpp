#include <bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		cout<<1;
		if(c[0]==d[0]&&c[1]==d[1])
		{
			cout<<111;
		}
		else
		{
			cout<<000;
		}
	}
	else
	{
		cout<<0000;
	}
	return 0;
}
