#include<bits/stdc++.h>
#define For(i, x, y) for (int i = x; i <= (int)y; i++)
#define foR(i, x, y) for (int i = x; i >= (int)y; i--)
#define fin(x) freopen(x, "r", stdin);
#define fou(x) freopen(x, "w", stdout);
#define fre(x) fin(x".in") fou(x".out")
#define ios cin.tie(0) -> sync_with_stdio(false);
#define itn int
#define tin int
#define tni int
#define nit int
#define nti int
#define imnt int
#define inmt int
using ll = long long;
using lll = __int128_t;
using namespace std;
vector<vector<int>>adj;
int ans;
int n, k;
vector<itn>cho;
int vis[1005], val[1005];
void dfs2(int x) {
	if (vis[x] || !val[x]) return;
	vis[x] = 1;
	for (auto i : adj[x]) dfs2(i); 
}
bool chk() {
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	for (auto i : cho) if (!vis[i]) cnt++, dfs2(i);
	return cnt < 3;
}
void dfs(int x) {
	if (x > k) {
		if (chk()) {
			int mx = 0;
			For(i, 1, n) {
				if (val[i]) continue;
				queue<pair<int, int>>q;
				q.push({i, 0});
				vector<int>dis(n + 1, 0), vis(n + 1, 0);
				while (!q.empty()) {
					int x = q.front().first, stp = q.front().second;
					q.pop();
					if (vis[x]) continue;
					vis[x] = 1;
					dis[x] = stp;
					for (auto i : adj[x]) q.push({i, stp + 1}); 
				}
				itn mn = 1e9;
				For(j, 1, n) if (val[j]) mn = min(mn, dis[j]);
				mx = max(mx, mn);
			}
			ans = min(ans, mx);
		}
		return;
	}
	For(i, 1, n) if (!val[i]) {
		val[i] = 1;
		cho.push_back(i);
		dfs(x + 1);
		cho.pop_back();
		val[i] = 0;
	}
}
int main() {
	fre("hub")
	ios
	int c, t;
	cin >> c >> t;
	if (c > 3) return 0;
	(void)c;
	while (t--) {
		cin >> n >> k;
		ans = 1e9;
		adj.resize(n + 1);
		For(i, 1, n) adj[i].clear();
		For(i, 1, n - 1) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1);
		cout << ans << '\n';
	}
}
