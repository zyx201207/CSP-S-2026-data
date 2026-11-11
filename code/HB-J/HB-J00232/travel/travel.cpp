#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll a,c;
string b,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else
	{
		cout<<1;
		if(b[0]!=d[0]||b[1]!=d[1])cout<<"000";
		else
		{
			cout<<1;
			if(!( b[2]<='C' && d[2]<='C' || b[2]>'C' && d[2]>'C' ))cout<<"00";
			else
			{
				cout<<1;
				if(abs(b[2]-d[2])!=1)cout<<0;
				else cout<<1;
			}
		}
	}
	return 0;
}

