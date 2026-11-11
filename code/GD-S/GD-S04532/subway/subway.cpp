#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
const ll INF=1e18;

struct node
{
	int v;
	ll w;
	bool operator <(const node &A) const
	{
		return w>A.w;
	}
};
struct qur
{
	int u, v;
	ll ans;
}qur[N];
int c, m, n, d, G, k, p[N], u1, v1, vis[N];
ll w1, dis[N];
vector<node> a[N];
priority_queue<node> q;
queue<int> q2;
void dij(int s)
{
	for (int i=1; i<=n+m; i++) dis[i]=INF, vis[i]=0;
	
	q.push({s, 0}), dis[s]=0;
	while (!q.empty())
	{
		int u=q.top().v;
		q.pop();
		
		if (vis[u]) continue;
		vis[u]=1;
		
		for (int i=0; i<a[u].size(); i++)
		{
			int v=a[u][i].v;
			ll w=a[u][i].w;
			
			if (dis[v]>dis[u]+w) dis[v]=dis[u]+w, q.push({v, dis[v]});
		}
	}
}
void dij2(int s)
{
	for (int i=1; i<=n+m; i++) dis[i]=INF, vis[i]=0;
	
	q2.push(s), dis[s]=0;
	while (!q2.empty())
	{
		int u=q2.front();
		q2.pop();
		
		if (vis[u]) continue;
		vis[u]=1;
		
		for (int i=0; i<a[u].size(); i++)
		{
			int v=a[u][i].v;
			ll w=a[u][i].w;
			
			if (dis[v]>dis[u]+w) dis[v]=dis[u]+w, q2.push(v);
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &m, &n, &d, &G);
	for (int i=1; i<=n; i++) scanf("%d", &p[i]);
	
	for (int i=1; i<=m; i++)
	{
		scanf("%d", &k);
		for (int j=1; j<=k; j++)
		{
			scanf("%d%lld", &u1, &w1);
			a[u1].push_back({i+n, w1});
			a[i+n].push_back({u1, w1});
		}
	}
	for (int i=1; i<=G; i++) scanf("%d%d", &qur[i].u, &qur[i].v), qur[i].ans=INF;
	for (int i=1; i<=m; i++)
	{
		if (c>=16 && c<=19) dij2(i+n);
		else dij(i+n);
		
		for (int j=1; j<=G; j++)
		{
			int u=qur[j].u, v=qur[j].v;
			qur[j].ans=min(qur[j].ans, dis[u]+dis[v]);
		} 
	}
	for (int i=1; i<=G; i++)
	{
		int u=qur[i].u, v=qur[i].v;
		printf("%lld\n", qur[i].ans+p[u]+p[v]);
	} 
	
	return 0;
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2 

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3



0 3 7 20 2
8 3 6 1 7 2 9

3   1 4    2 5     5 100
3   2 6    3 1     7 2
4   3 2    5 100   4 6      6 7

1 6
2 3


8+4+5+1+2+6+7+2

8+4+5+

O(mnlogn+mq)
*/
