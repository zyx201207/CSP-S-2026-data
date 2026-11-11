#include<bits/stdc++.h>
using namespace std;
using ll=long long;

string a,b,c,d;

void solve()
{
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return;
	}
	if(b[0]!=d[0] || b[1]!=d[1])
	{
		cout<<"1000";
		return;
	}
	if((b[2]>'C' && d[2]<='C') || (b[2]<='C' && d[2]>'C'))
	{
		cout<<"1100";
		return;
	}
	if(b[2]<='C' && d[2]<='C')
	{
		if(abs(d[2]-b[2])!=1)
		{
			cout<<"1110";
			return;
		}
	}
	if(b[2]>'C' && d[2]>'C')
	{
		if(abs(d[2]-b[2])!=2)
		{
			cout<<"1110";
			return;
		}
	}
	cout<<"1111";
	return;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
} 
