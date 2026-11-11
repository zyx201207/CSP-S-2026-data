#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 1e3 + 5, M = 1e6 + 5;

vector<pii> g[N], e[M];
bool vis[N];
int c, n, m, d, q, w[M], idx, dist[N][N];

void add (int u, int v, int w) {
	g[u].push_back ({v, w});
	g[v].push_back ({u, w});
	return ;
}

void dijkstra (int s)
{
	for (int i = 1; i <= n; i++) dist[s][i] = 1e18, vis[i] = false;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[s][s] = 0, pq.push ({0, s});
	while (!pq.empty ())
	{
		int dis = pq.top().first, u = pq.top().second;
		pq.pop ();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto x : g[u])
		{
			int to = x.first, w = x.second;
			if (dist[s][to] > dis + w) 
			{
				dist[s][to] = dis + w;
				pq.push ({dis + w, to});
			}
		}
	}
	return ;
}

signed main ()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	
	for (int i = 1, k, a, t; i <= n; i++) 
	{
		cin >> k;
		while (k--) 
		{
			cin >> a >> t;
			for (auto x : e[a]) add (x.first, i, x.second + t);
			e[a].push_back ({i, t});
		}
	}
	
	for (int i = 1; i <= n; i++) dijkstra (i);
	for (int p = 1, x, y; p <= q; p++)
	{
		cin >> x >> y;
		int ans = 1e18;
		for (auto i : e[x]) for (auto j : e[y]) ans = min (ans, w[x] + w[y] + dist[i.first][j.first]+ i.second + j.second);
		cout << ans << "\n";
	}	
	
	return 0;
}