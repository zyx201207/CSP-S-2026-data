#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5 + 5, Q = 1e5 + 5;
struct edge {
	int v, w, l;
} e[M];
struct qy {
	int t, i;
};
vector<edge> g[M];
vector<qy> v[M];
queue<edge> qe;
int a[M], ans[Q], dis[M];
void bfs1(int s) {
	int val;
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	qe.push({s, 0, 0});
	while (!qe.empty()) {
		auto u = qe.front();
		qe.pop();
		for (auto v: g[u.v]) {
			val = dis[u.v] + (u.l == v.l ? 0 : v.w);
			if (dis[v.v] > val) {
				dis[v.v] = val;
				qe.push({v.v, 0, v.l});
			}
		}
	}
}
void bfs2(int s) {
	int val;
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	qe.push({s, 0, 0});
	while (!qe.empty()) {
		auto u = qe.front();
		qe.pop();
		for (auto v: g[u.v]) {
			val = dis[u.v] + v.w;
			if (dis[v.v] > val) {
				dis[v.v] = val;
				qe.push({v.v, val, 0});
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, k, s, t, ps, pt, x, y, maxs = 0;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> a[i];
	if (c <= 15) {
		for (int i = 1; i <= n; i++) {
			cin >> k;
			for (int j = 1; j <= k; j++) {
				cin >> e[j].v >> e[j].w;
				maxs = max(maxs, e[j].v);
			}
			for (int a = 1; a <= k; a++)
				for (int b = a + 1; b <= k; b++) {
					g[e[a].v].push_back({e[b].v, e[a].w + e[b].w, 0});
					g[e[b].v].push_back({e[a].v, e[a].w + e[b].w, 0});
				}
			memset(e, 0, sizeof e);
		}
		for (int i = 1; i <= q; i++) {
			cin >> x >> y;
			v[x].push_back({y, i});
		}
		for (int i = 1; i <= maxs; i++) 
			if (v[i].size() != 0) {
				bfs2(i);
				for (auto it: v[i])
					ans[it.i] = dis[it.t] + a[it.t] + a[i];
			}
		for (int i = 1; i <= q; i++) cout << ans[i] << endl;
	} else {
		for (int i = 1; i <= n; i++) {
			cin >> k >> ps >> pt;
			for (int j = 1; j < k; j++) {
				maxs = max(maxs, ps);
				cin >> s >> t;
				g[s].push_back({ps, pt + t, i});
				g[ps].push_back({s, pt + t, i});
				ps = s, pt = t;
			}
			maxs = max(maxs, ps);
		}
		for (int i = 1; i <= q; i++) {
			cin >> x >> y;
			v[x].push_back({y, i});
		}
		for (int i = 1; i <= maxs; i++)
			if (v[i].size() != 0) {
				bfs1(i);
				for (auto it: v[i])
					ans[it.i] = dis[it.t] + a[it.t] + a[i];
			}
		for (int i = 1; i <= q; i++) cout << ans[i] << endl;
	}
	return 0;
}
