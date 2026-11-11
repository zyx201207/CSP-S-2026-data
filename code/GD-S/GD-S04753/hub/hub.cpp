#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> g[N], v;
bool vis[N];
queue<int> q;
int n, k, dis[N], minn, minc;
void bfs1(int s) {
	vis[s] = true;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int c: g[u])
			if (binary_search(v.begin(), v.end(), c) && !vis[c]) {
				vis[c] = true;
				q.push(c);
			}
	}
}
void bfs2(int s) {
	dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v: g[u])
			if (dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}
int check() {
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof vis);
	int ind, maxn = 0;
	bfs1(v[0]);
	for (auto it: v)
		if (!vis[it]) {
			ind = it;
			break;
		}
	bfs1(ind);
	for (auto it: v)
		if (!vis[it]) return 0;
	for (auto it: v) bfs2(it);
	for (int i = 1; i <= n; i++) maxn = max(maxn, dis[i]);
	return maxn;
}
void dfs(int ind, int cnt) {
	if (ind == n + 1) {
		if (cnt != k) return ;
		int val = check();
		if (val == 0) return ;
		if (val < minn) {
			minn = val;
			minc = 1;
		} else if (val == minn) minc++;
		return ;
	}
	dfs(ind, cnt);
	v.push_back(ind);
	if (cnt < k) dfs(ind + 1, cnt + 1);
	v.pop_back();
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, x, y;
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		minn = 1e9, minc = 0;
		dfs(1, 0);
		cout << minc << endl;
		for (int i = 1; i <= n; i++) g[i].clear();
	}
}
