#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
ll w[1000005];
vector<pair<ll,ll>> g[1000005];
ll dis[1005][1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for (int i=1;i<=n;i++)
	{
		int cn;
		scanf("%d",&cn);
		for (int j=1;j<=cn;j++)
		{
			ll a,t;
			scanf("%lld %lld",&a,&t);
			g[a].push_back(make_pair(i,t));
		}	
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			dis[i][j]=1e18;
			if (i==j) dis[i][j]=0;
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (auto u:g[i])
		{
			for (auto v:g[i])
			{
				if (u==v) continue;
				int uid=u.first;
				int vid=v.first;
				ll uw=u.second;
				ll vw=v.second;
				dis[uid][vid]=min(dis[uid][vid],uw+vw);
			}
		}
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (i!=j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		if (u==v)
		{
			printf("0\n");
			continue;
		}
		ll ans=w[u]+w[v],val=1e18;
		for (auto l:g[u])
		{
			for (auto r:g[v])
			{
				val=min(val,l.second+r.second+dis[l.first][r.first]);
				//if (u==112&&v==111) cout<<val<<"\n";
			}
		}
		printf("%lld\n",ans+val);
	}
	return 0;
}
