#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pii;
vector<pii> G[501000];
long long w[501000]={0},dist[501000]={0},vis[501000]={0};
void dij(long long s)
{
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	priority_queue<pii> q;
	q.push({0,s});
	dist[s]=0;
	while(!q.empty())
	{
		long long u=q.top().second;
		q.pop();
//		if(vis[u]) continue;
//		vis[u]=1;
		for(pii x:G[u])
		{
			long long v=x.first;
			long long w=x.second;
			if(dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(long long i=1;i<=n;i++)
	{
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++)
		{
			long long a,t;
			scanf("%lld%lld",&a,&t);
			G[m+i].push_back({a,t});
			G[a].push_back({m+i,t});
		}
	}
	while(q--)
	{
		long long x,y;
		scanf("%lld%lld",&x,&y);
		dij(x);
		printf("%lld\n",dist[y]+w[x]+w[y]);
	}
	return 0;
}
