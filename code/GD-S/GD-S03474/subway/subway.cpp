#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
const long long inf=LLONG_MAX>>4;
struct Edge
{
	int to;
	long long w;
};
int c, n, m, d, q, total;
long long dist[maxn], ztot[maxn];
bool vis[maxn];
vector<Edge> edge[maxn];
long long dijkstra(int st, int ed)
{
	for(int i=1; i<=total; i++) dist[i]=inf, vis[i]=0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	dist[st]=0;
	pq.push(make_pair(dist[st], st));
	while(!pq.empty())
	{
		pair<long long, int> a=pq.top();
		pq.pop();
		int u=a.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int j=0; j<edge[u].size(); j++)
		{
			int v=edge[u][j].to;
			long long w1=edge[u][j].w;
			if(w1+dist[u]<dist[v])
			{
				dist[v]=w1+dist[u];
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	return dist[ed];
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	total=n+m*2;
	for(int i=1; i<=m; i++)
	{
		long long w1;
		scanf("%lld ", &w1);
		Edge e;
		e.to=i+m, e.w=w1;
		edge[i].push_back(e);
		e.to=i;
		edge[i+m].push_back(e);
	}
	for(int i=1; i<=n; i++)
	{
		int k;
		scanf("%d", &k);
		for(int j=1; j<=k; j++)
		{
			int v;
			long long w1;
			scanf("%d %lld", &v, &w1);
			v+=m;
			int pos=m*2+i;
			Edge e;
			e.to=v, e.w=w1;
			edge[pos].push_back(e);
			e.to=pos;
			edge[v].push_back(e);
		}
	}
	for(int i=1; i<=q; i++)
	{
		int st, ed;
		scanf("%d %d", &st, &ed);
		long long ans=dijkstra(st, ed);
		printf("%lld\n", ans);
	}
	return 0;
}



