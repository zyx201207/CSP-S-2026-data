#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pil = pair<int, i64>;
using pli = pair<i64, int>;
const int N = 510, M = 5e5 + 10;

int C, n, m, d, q, w[M], k[N], sk[N];
vector<int> a[N], t[N], l[M];
unordered_map<int, int> id[N], c[N];
vector<pil> G[M];
bitset<M> bs[N], vs;
i64 dis[M];

void dij(int s) {
	memset(dis, 0x3f, sizeof(dis)), vs.reset();
	priority_queue<pli, vector<pli>, greater<pli>> Q;
	dis[s] = 0, Q.push({0LL, s});
	while (!Q.empty()) {
		int u = Q.top().second; Q.pop();
		if (vs[u]) continue;
		vs.set(u);
		for (auto ed : G[u]) {
			int v = ed.first;
			i64 w = ed.second;
			if (dis[u] + w < dis[v])
				dis[v] = dis[u] + w, Q.push({dis[v], v});
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i], sk[i] = sk[i - 1] + k[i];
		a[i].resize(k[i] + 1), t[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j], l[a[i][j]].emplace_back(i);
			id[i][a[i][j]] = j, bs[i].set(a[i][j]);
			if (j > 1) {
				int x = sk[i - 1] + j;
				G[x - 1].emplace_back(x, 0LL), G[x].emplace_back(x - 1, 0LL);
			}	
		}
		for (int j = 1; j < i; j++) {
			bitset<M> tp = bs[i] & bs[j];
			for (int x = tp._Find_first(); x < (int)tp.size(); x = tp._Find_next(x)) {
				int w = t[i][id[i][x]] + t[j][id[j][x]];
				int u = sk[i - 1] + id[i][x], v = sk[j - 1] + id[j][x];
				G[u].emplace_back(v, w), G[v].emplace_back(u, w);
			}
		}
	}
	while (q--) {
		int u, v; cin >> u >> v;
		for (int x : l[u]) G[0].emplace_back(sk[x - 1] + id[x][u], w[u] + t[x][id[x][u]]);
		for (int x : l[v]) G[sk[x - 1] + id[x][v]].emplace_back(sk[n] + 1, w[v] + t[x][id[x][v]]);
		dij(0), cout << dis[sk[n] + 1] << "\n";
		G[0] = vector<pil>();
		for (int x : l[v]) G[sk[x - 1] + id[x][v]].pop_back();
	}
	return 0;
}
