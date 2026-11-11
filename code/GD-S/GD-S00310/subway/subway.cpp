#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
const int N=5e4+1010;
int c,n,m,d,q;
int w[N];
int dis[501][N];
int dis2[51][N*10];
bool b[N];
vector<pair<int,int>> e[N];

void dijkstra(int s)
{
	priority_queue<pair<int,int>> q;
	vector<bool> vis(N);
	for(int i=1; i<=n+m; i++) dis[s][i]=1e9;
	dis[s][s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto it:e[u])
		{
			int v=it.first,w=it.second;
			if(dis[s][v]>dis[s][u]+w)
			{
				dis[s][v]=dis[s][u]+w;
				q.push({-dis[s][v], v});
			}
		}
	}
}
void dijkstra2(int s)
{
	priority_queue<pair<int,int>> q;
	vector<bool> vis(N);
	for(int i=1; i<=n+m; i++) dis2[s][i]=1e9;
	dis2[s][s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto it:e[u])
		{
			int v=it.first,w=it.second;
			if(dis2[s][v]>dis2[s][u]+w)
			{
				dis2[s][v]=dis2[s][u]+w;
				q.push({-dis2[s][v], v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i=1; i<=m; i++)
		scanf("%lld", &w[i]);
	for(int i=1; i<=n; i++)
	{
		int k;
		scanf("%lld", &k);
		for(int j=1; j<=k; j++)
		{
			int a,t;
			scanf("%lld%lld", &a, &t);
			e[i].push_back({n+a,t});
			e[n+a].push_back({i,t});
		}
	}
	if(n<=51)
	for(int i=1; i<=n; i++)
	dijkstra2(i);
	else
	for(int i=1; i<=n; i++)
	dijkstra(i);
	if(n<=51)
	for(int i=1; i<=q; i++)
	{
		int s,t;
		scanf("%lld%lld", &s, &t);
		int ans=1e9;
		for(auto it:e[s+n])
		{
			int j=it.first;
			ans=min(ans, dis2[j][s+n]+dis2[j][t+n]+w[s]+w[t]);
		}
		printf("%lld\n", ans);
	}
	else
	for(int i=1; i<=q; i++)
	{
		int s,t;
		scanf("%lld%lld", &s, &t);
		int ans=1e9;
		for(auto it:e[s+n])
		{
			int j=it.first;
			ans=min(ans, dis[j][s+n]+dis[j][t+n]+w[s]+w[t]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
