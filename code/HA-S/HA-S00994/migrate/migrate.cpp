#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 2e6 + 5;

bool vis[N];
vector<pii> e[N];
vector<int> g[N];
int c, T, n, d, x[N], dist[N], f[N], in[N], ans;

void dijkstra (int s)
{
	for (int i = 1; i <= n; i++) dist[i] = 1e18, vis[i] = false;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[s] = 0; pq.push ({0, s});
	while (!pq.empty ())
	{
		int dis = pq.top ().first, u = pq.top ().second;
		pq.pop ();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto x : e[u])
		{
			int to = x.first, w = x.second;
			if (dist[to] > w + dis)
			{
				dist[to] = w + dis;
				pq.push ({w + dis, to});
			}
		}
	}
	return ;
}

void init (int s)
{
	for (int i = 1; i <= n; i++) g[i].clear (), in[i] = f[i] = 0;
	for (int i = s; i <= n; i++) 
	{
		for (auto x : e[i]) {
			int to = x.first, w = x.second;
			if (dist[to] == dist[i] + w) g[i].push_back (to), in[to]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) if (dist[i] != 1e18 && in[i] == 0) f[i] = 1, q.push (i);
	while (!q.empty ())
	{
		int u = q.front (); q.pop ();
		for (auto v : g[u])
		{
			in[v]--, f[v] += f[u];
			if (in[v] == 0) q.push (v);
		}		
	}
	
	for (int i = 1; i <= n; i++) if (f[i] == 2) ans++;
	return ;
}

void solve ()
{
	cin >> n >> d, ans = 0;
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i <= n; i++) cin >> x[i];
	sort (x + 1, x + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) 
		{
			if (x[j] - x[i] > d) break;
			else e[i].push_back ({j, 1});
		} 
	}
	for (int i = 1; i <= n; i++) {
		dijkstra (i); init (i);
	}
	cout << ans << "\n";
	return ;
}

signed main ()
{
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	
	cin >> c >> T;
	while (T--) solve ();
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/