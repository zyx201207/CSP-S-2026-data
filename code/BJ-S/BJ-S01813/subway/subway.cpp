#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define faster ios::sync_with_stdio(0);cin.tie(0)
ll c,n,m,d,q,a[500005],dis[502][502];
struct _
{
	ll v,w;
};
basic_string<_>con[500005];
int main()
{
	faster;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (ll i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for (ll i=1;i<=n;i++)
	{
		for (ll j=1;j<=n;j++)
		{
			dis[i][j]=1e18;
		}
	}
	for (ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		dis[i][i]=0;
		while (k--)
		{
			ll u,w;
			cin>>u>>w;
			con[u].pb({i,w});
		}
	}
	for (ll i=1;i<=m;i++)
	{
		for (_ x:con[i])
		{
			for (_ y:con[i])
			{
				dis[x.v][y.v]=min(dis[x.v][y.v],x.w+y.w);
				dis[y.v][x.v]=min(dis[y.v][x.v],x.w+y.w);
			}
		}
	}
	for (ll k=1;k<=n;k++)
	{
		for (ll i=1;i<=n;i++)
		{
			for (ll j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while (q--)
	{
		ll u,v;
		cin>>u>>v;
		ll res=1e18;
		for (_ x:con[u])
		{
			for (_ y:con[v])
			{
				res=min(res,dis[x.v][y.v]+x.w+y.w+a[u]+a[v]);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}