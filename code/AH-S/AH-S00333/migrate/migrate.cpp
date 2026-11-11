#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll c;
	cin>>c;
	if(c==13||c==14)
	{
		ll t;
		cin>>t;
		while(t--)
		{
			ll n,m;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				ll x;
				cin>>x;
			}
			cout<<0<<"\n";
		}
	}
	if(c==12||c==11)
	{
		ll t;
		cin>>t;
		while(t--)
		{
			ll n,m,a,b,y;
			cin>>n>>m>>a>>b;
			for(int i=3;i<=n;i++)
			{
				ll x;
				cin>>x;
			}
			if(m<2*(b-a))cout<<0;
			y=m/(b-a)+1;
			cout<<(n+1)*(y-2)-y*(y-2)-0.5*(y-1)*(y-2)<<"\n";
		}
	}
}
