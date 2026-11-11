#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node
{
	int to; ll val;
};

bool operator < (Node x, Node y)
{
	return x.val > y.val;
}

const int MAXM = 5e5 + 5, MAXN = 5e2 + 5, MAXQ = 1e5 + 5; const ll Inf = 1e18;

bool is[MAXM + MAXN]; int c, d, m, n, q, qx[MAXQ], qy[MAXQ]; ll ans[MAXQ], dis[MAXM + MAXN], ww[MAXM];

vector <Node> G[MAXM + MAXN];

void Bfs(int s)
{
	for (int i = 1; i <= m + n; i ++)
	{
		dis[i] = 0; is[i] = 0;
	}
	
	is[s] = 1; queue <int> q; q.push(s);
	
	ll T = G[s][0].val;
	
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		
		for (auto e : G[u])
		{
			int v = e.to;
			
			if (is[v]) continue; dis[v] = dis[u] + T; is[v] = 1; q.push(v);
		}
	}
}

void Dijkstra(int s)
{
	for (int i = 1; i <= m + n; i ++)
	{
		dis[i] = Inf; is[i] = 0;
	}
	
	dis[s] = 0; priority_queue <Node> pq; pq.push(Node {s, 0});
	
	while (!pq.empty())
	{
		int u = pq.top().to; ll d = pq.top().val; pq.pop();
		
		if (is[u]) continue; is[u] = 1;
		
		for (auto e : G[u])
		{
			int v = e.to; ll w = e.val;
			
			if (is[v]) continue;
			
			if (dis[v] > d + w)
			{
				dis[v] = d + w; pq.push(Node {v, dis[v]});
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i ++) cin >> ww[i];
	
	for (int i = 1; i <= n; i ++)
	{
		int k; cin >> k;
		
		for (int j = 1; j <= k; j ++)
		{
			int a; ll t; cin >> a >> t;
			
			G[a].push_back({i + m, t}); G[i + m].push_back({a, t});
		}
	}
	
	for (int i = 1; i <= q; i ++) cin >> qx[i] >> qy[i];
	
	for (int i = 1; i <= q; i ++) ans[i] = Inf;
	
	for (int i = m + 1; i <= m + n; i ++)
	{
		if (c <= 19 && c >= 12) Bfs(i); else Dijkstra(i);
		
		for (int j = 1; j <= q; j ++) ans[j] = min(ans[j], dis[qx[j]] + dis[qy[j]]);
		
		//for (int j = 1; j <= n + m; j ++) cout << dis[j] << " "; cout << "\n";
	}
	
	for (int i = 1; i <= q; i ++)
	{
		ans[i] += ww[qx[i]] + ww[qy[i]]; cout << ans[i] << "\n";
	}
	
	return 0;
}
