#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
ll w[500010];
vector<pair<int,ll> > dy[500010];
ll G[510][510];
inline void Floyd()
{
	for(register int k=1;k<=n;k++)
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<=n;j++)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(register int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(register int i=1;i<=n;i++)
	{
		int len;
		scanf("%d",&len);
		for(register int j=1;j<=len;j++)
		{
			int x;ll ss;
			scanf("%d%lld",&x,&ss);
			dy[x].push_back({i,ss});
		}
	}
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=n;j++)
		{
			if(i==j) G[i][j]=0;
			else G[i][j]=1e18;
		}
	for(register int i=1;i<=m;i++)
		for(register int j=0;j<dy[i].size();j++)
			for(register int k=j+1;k<dy[i].size();k++)
			{
				int u=dy[i][j].first,v=dy[i][k].first;ll ss=dy[i][j].second+dy[i][k].second;
				G[u][v]=min(G[u][v],ss),G[v][u]=min(G[v][u],ss);
			}
	Floyd();
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=1e18;
		for(register int i=0;i<dy[x].size();i++)
			for(register int j=0;j<dy[y].size();j++)
			{
				int u=dy[x][i].first,v=dy[y][j].first;ll ss=dy[x][i].second+dy[y][j].second;
				ans=min(ans,w[x]+w[y]+G[u][v]+ss);
			}
		printf("%lld\n",ans);
	}
	return 0;
}
