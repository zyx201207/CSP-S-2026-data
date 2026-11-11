#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 10;
const int M = 2e6 + 10; 
const int maxn = 30;
const int maxm = 5e2 + 10;

int c, n, m, k[N], d, q, x[N], y[N];
int dis[maxm], w[N];
vector<int> a[maxm], t[maxm];
int num[N][maxn], id[N][maxn], tot[N], vis[maxm][maxm], fl[maxm];

struct node
{
	int to, id;
	int w;
};

struct edge
{
	int dist;
	int num, id;
	inline bool operator <(const edge &N) const
	{
		return dist > N.dist;
	}
};

vector<node> e[M];

inline int dij(int s, int t)
{
	memset(dis, 0x3f3f3f3f3f3f3f3f, sizeof dis);
	memset(fl, 0, sizeof fl);
	priority_queue<edge> q;
	for(int i = 1; i <= tot[s]; ++ i)
	{
		q.push({0, id[s][i], s});
		dis[id[s][i]] = 0;
	}

	while(!q.empty())
	{
		edge N = q.top(); q.pop();
		int u = N.num, now = N.id;
		if(fl[u]) continue;
		fl[u] = 1;
		for(int i = 0; i < e[u].size(); ++ i)
		{
			int v = e[u][i].to, to = e[u][i].id;
			int w = e[u][i].w;
			int id1 = lower_bound(id[now] + 1, id[now] + tot[now] + 1, u) - id[now];
			int id2 = lower_bound(id[to] + 1, id[to] + tot[to] + 1, u) - id[to];
			if(num[now][id1] > num[to][id2]) continue;
			if(dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push({dis[v], v, to});
			}
		}
	}

	int ans = 0x3f3f3f3f3f3f3f3f;

	for(int i = 1; i <= tot[t]; ++ i) ans = min(ans, dis[id[t][i]]);
	return ans;
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; ++ i) scanf("%lld", &w[i]);
	for(int i = 1; i <= n; ++ i)
	{
		scanf("%lld", &k[i]);
		a[i].push_back(0), t[i].push_back(0);
		for(int j = 1, xx, yy; j <= k[i]; ++ j)
		{
			scanf("%lld%lld", &xx, &yy), a[i].push_back(xx), t[i].push_back(yy);
			num[a[i][j]][++ tot[a[i][j]]] = j, id[a[i][j]][tot[a[i][j]]] = i;
		}
	}
	for(int i = 1; i <= m; ++ i) 
	for(int i = 1; i <= m; ++ i)
	{
		for(int j = 1; j <= tot[i]; ++ j)
		{
			for(int k = j + 1; k <= tot[i]; ++ k)
			{
				if(!vis[id[i][j]][id[i][k]])
				{
					e[id[i][j]].push_back({id[i][k], i, t[id[i][j]][num[i][j]] + t[id[i][k]][num[i][k]]});
					e[id[i][k]].push_back({id[i][j], i, t[id[i][j]][num[i][j]] + t[id[i][k]][num[i][k]]});
					vis[id[i][j]][id[i][k]] = vis[id[i][k]][id[i][j]] = 1;
				}
			}
		}
	}
	for(int i = 1; i <= q; ++ i)
	{
		scanf("%lld%lld", &x[i], &y[i]);
		int ans = dij(x[i], y[i]);
		printf("%lld\n", ans + w[x[i]] + w[y[i]]);
	}
//	puts("A");
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
