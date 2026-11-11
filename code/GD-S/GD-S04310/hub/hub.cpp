#include <iostream>
#include <vector>
#include <queue>

#define ll long long

#define eb emplace_back

using namespace std;

namespace sub {
	const int N = 110;
	
	vector <int> g[N];
	
	int n, k, ans;
	
	int dis[N];
	
	bool vis[N], bj[N];
	
	void dfs (int u) {
		bj[u] = 0;
		for (int v : g[u])
			if (bj[v]) dfs (v);
	}
	
	bool check () {
		for (int i = 1; i <= n; ++ i) bj[i] = vis[i];
		int cnt = 0;
		for (int i = 1; i <= n; ++ i)
			if (bj[i]) {
				++ cnt;
				if (cnt > 2) return false;
				dfs (i);
			}
		return true;
	}
	
	void solve () {
		cin >> n >> k, ans = n;
		for (int i = 1, u, v; i < n; ++ i) cin >> u >> v, g[u].eb (v), g[v].eb (u);
		for (int S = 0; S < (1 << n); ++ S) {
			int cnt = 0;
			for (int i = 1; i <= n; ++ i)
				if ((S >> (i - 1)) & 1) vis[i] = 1, ++ cnt;
			if (cnt == k && check ()) {
				queue <int> q;
				for (int i = 1; i <= n; ++ i) if (vis[i]) q.push (i);
				while (!q.empty ()) {
					int u = q.front ();
					q.pop ();
					for (int v : g[u])
						if (!dis[v] && !vis[v]) dis[v] = dis[u] + 1, q.push (v);
				}
				int res = 0;
				for (int i = 1; i <= n; ++ i) res = max (res, dis[i]), dis[i] = 0;
				ans = min (ans, res);
			}
			for (int i = 1; i <= n; ++ i)
				if ((S >> (i - 1)) & 1) vis[i] = 0;
		}
		for (int i = 1; i <= n; ++ i) g[i].clear ();
		cout << ans << '\n';
	}
}

int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
	
	int c, t;
	cin >> c >> t;
	while (t --) {
		if (c <= 3) sub :: solve ();
	}
	
	return 0;
} 
