#include<bits/stdc++.h>
#define ll long long
#define endl '\n';
using namespace std;
const ll maxn=5e5+10;
ll c,n,m,d,q,w[maxn],plm=0;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll cnm;
			cin>>cnm;
			plm=cnm;
		} 
	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y];
		ans=ans+(y-x)*2*plm;
		cout<<ans<<endl;
	}
	return 0;
}
