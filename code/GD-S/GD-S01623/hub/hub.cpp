#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define pp pair<int, int>
#define ft first
#define sd second
const int N = 1e6 + 5;
int c, t, n, k, ans;
int vis[N], in[N], d[N];
vector<int> g[N], nw;
void init() {
	ans = 1e18;
	for (int i = 1; i <= n; i++) g[i].clear();
}
int bfs() {
	queue<pp> q;
	for (int i = 1; i <= n; i++) d[i] = 0;
	for (int i : nw) q.push({0, i});
	while (!q.empty()) {
		auto tp = q.front();
		q.pop();
		int u = tp.sd, z = tp.ft;
		for (int i : g[u]) 
			if (!d[i] && !in[i]) {
				d[i] = z + 1;
				q.push({d[i], i});
			}
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) Max(mx, d[i]);
	return mx;
}
void dfs1(int x) {
	vis[x] = 1;
	for (int v : g[x]) 
		if (!vis[v]) dfs1(v);
}
bool ck() {
	int cnt = 0;
	for (int i : nw) vis[i] = 0; 
	for (int i : nw)
		if (!vis[i]) cnt++, dfs1(i);
	return cnt < 3;
}
void dfs(int x, int y) {
	if (x > n || !y) {
		if (y || !ck()) return ;
		Min(ans, bfs());
		return ;
	}
	dfs(x + 1, y);
	if (y) {
		nw.push_back(x), in[x] = 1;
		dfs(x + 1, y - 1); 
		nw.pop_back(), in[x] = 0;
	}
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k, init();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, k), cout << ans << "\n";
	}
	return 0;
}

