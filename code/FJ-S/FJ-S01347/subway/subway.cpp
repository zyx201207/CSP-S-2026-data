#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
ll c,n,m,d,q;
ll w[500010];
ll a[500010][25];
ll t[500010][25], cnt[500010];
ll adj[510][510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++) scanf("%lld",&w[i]);
	for(int i=1; i<=n; i++)
	{
		ll k;
		scanf("%lld",&k);
		for(int j=1; j<=k; j++)
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			cnt[x]++;
			a[x][cnt[x]] = i;
			t[x][cnt[x]] = y;
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i != j)
				adj[i][j] = 1e18;
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=cnt[i]; j++)
		{
			for(int k=j+1; k<=cnt[i]; k++)
			{
				int u = a[i][j], v = a[i][k];
				ll tt = t[i][j] + t[i][k];
				adj[u][v] = adj[v][u] = min(adj[u][v],tt);
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			for(int k=1; k<=n; k++)
			{
				adj[i][j] = adj[j][i] = min(adj[i][j],adj[i][k]+adj[k][j]);
			}
		}
	}
	while(q--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll ans1 = w[x] + w[y], ans2 = 1e18;
		for(int i = 1; i<=cnt[x]; i++)
		{
			for(int j=1; j<=cnt[y]; j++)
			{
				int u = a[x][i], v = a[y][j];
				ans2 = min(ans2,t[x][i]+t[y][j]+adj[u][v]);
			}
		}
		printf("%lld\n",ans1+ans2);
	}
	return 0;
}