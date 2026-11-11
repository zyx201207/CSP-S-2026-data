#include <bits/stdc++.h>

using namespace std;

const int N = 4e3 + 10;

ifstream fin("hub.in");
ofstream fout("hub.out");
#define cin fin
#define cout fout

int n, k, vis[N], from[N], d[N], ext[N];
vector<int> adj[N];

void dfs(int x, int fa)
{
	for (int y : adj[x])
		if (y != fa) dfs(y, x), ext[x] = max(ext[x], ext[y] + 1);
}

bool check(int mid)
{
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			memset(vis, 0, sizeof(int) * (n + 1));
			memset(from, 0, sizeof(int) * (n + 1));
			queue<int> q;
			q.push(i);
			vis[i] = true;
			while (!q.empty())
			{
				int u = q.front(); q.pop();
				for (int v : adj[u]) 
					if (!vis[v]) q.push(v), vis[v] = true, from[v] = u;
			}
			int x = from[j];
			int y = x;
			while (y != i && from[y] != i) y = from[y];
			memset(vis, 0, sizeof(int) * (n + 1));
			memset(d, 0, sizeof(int) * (n + 1));
			
			if (from[j] != i)
			{
			q.push(x);
			if (x != y) q.push(y);
			d[x] = d[y] = 1, vis[x] = vis[y] = true;
			
			bool flag = false;
			while (!q.empty())
			{
				int u = q.front(); q.pop();
				if (u == i || u == j) continue;
				if (d[u] > mid) flag = true;
				for (int v : adj[u]) 
					if (!vis[v]) q.push(v), vis[v] = true, d[v] = d[u] + 1;
			}
			if (flag) continue;	
			}
			
			memset(ext, 0, sizeof(int) * (n + 1));
			dfs(j, x), dfs(i, y);
			int cnt = 0;
			for (int t = 1; t <= n; t++)
				if (ext[t] >= mid || t == i || t == j) cnt++;//, cerr << i << ' '; cerr << endl;
//			cerr << mid << ' ' << i << ' ' << j << ' ' << cnt << endl;
			if (cnt <= k) return true;
		}
	return false;
}

void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1, u, v; i <= n - 1; i++) cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	int l = 0, r = n; 
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
}

signed main()
{
	int c, t; cin >> c >> t;
	while (t--) solve();	
}

