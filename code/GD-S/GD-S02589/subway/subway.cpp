#include <bits/stdc++.h>
#define ll long long
using namespace std;
const double eps = 1e-12;
const int N = 5e5 + 20; //记得改回5e5 + 20 
int m, v, n, d, q, c;
int w[N];
int k[600];
int a[600][N], t[600][N];
int x, y;
int te_yang2 = -1;
bool yang2 = 1;
vector <int> G[600];
ll bfs_te_yang2 (int u, int v) // u是起点,v是终点 
{
	bool vis[600];
	queue <pair<int, ll> > s;
	while (!s.empty()) s.pop();
	memset (vis, 0, sizeof (vis));
	s.push ({u, 0LL});
	while (!s.empty())
	{
		auto news_top = s.front ();
		s.pop();
		if (news_top.first == v)
		{
			return news_top.second + w[u] + w[v];
		}
		for (auto TZ : G[news_top.first])
		{
			for (int j = 1; j <= k[TZ]; ++j)
			{
				if (!vis[a[TZ][j]])
				{
					vis[a[TZ][j]] = true;
					s.push ({a[TZ][j], news_top.second + te_yang2});	
				}	
			}
		}
	}
	return -1;
}
ll dis[N];
ll Dijkstra (int xx, int yy)
{
	bool vis[600];
	memset (vis, 0, sizeof (vis));
	priority_queue <pair<ll, int> > s;
	s.push ({0, xx});
	memset (dis, 0x3f3f3f3f, sizeof (dis));
	dis[xx] = 0;
	while (!s.empty ())
	{
		pair <ll, int> news_top = s.top ();
		s.pop();
		ll v = news_top.first, u = news_top.second;
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto TZ : G[u])
		{
			for (int j = 1; j <= k[TZ]; ++j)
			{
				if (dis[a[TZ][j]] > dis[u] + t[TZ][j] + t[TZ][TZ])
				{
					dis[a[TZ][j]] = dis[u] + t[TZ][j] + t[TZ][TZ];
					s.push ({dis[a[TZ][j]], a[TZ][j]});
				}
			}
		}
	}
	return dis[yy] + w[xx] + w[yy];
}
int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
//	cout.tie (0);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j)
		{
			cin >> a[i][j] >> t[i][j];
			G[a[i][j]].push_back (i);
			if (te_yang2 == -1) te_yang2 = t[i][j];
			else if (t[i][j] != te_yang2)
			{
				yang2 = 0;
			}
			
		}
	}

	//对于特殊性质2，可以进行bfs,第一个答案一定是最优解 
	if (yang2)
	{
		for (int i = 1; i <= q; ++i)
		{
			cin >> x >> y;
			cout << bfs_te_yang2 (x, y) << '\n';
		}	
		return 0;
	}else{
		// Dijkstra
		for (int i = 1; i <= q; ++i)
		{
			cin >> x >> y;
			cout << Dijkstra(x, y) << endl;
		}
	}
	return 0;
}
