#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x; short f; char ch;
inline ll read() {
	x = 0, f = 1, ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f;
}
inline void write(ll s) {
	if (s < 0) putchar('-'), s = -s;
	if (s > 9) write(s / 10);
	putchar(s % 10 + 48);
}
vector<vector<pair<int, ll>>> G;
/*vector<ll> dis;
bitset<110101> vis;
ll dijkstra(int s, int t) {
	fill(dis.begin(), dis.end(), 5e12);
	vis.reset();
	dis[s] = 0;
	int Min, p;
	while (true) {
		Min = 5e12;
		for (int i = 1; i < dis.size(); i++) {
			if (vis[i]) continue;
			if (Min > dis[i]) Min = dis[i], p = i;
		}
		if (p == t) return dis[p];
		vis[p] = 1;
		for (auto &i : G[p]) {
			if (vis[i.first]) continue;
			dis[i.first] = min(dis[i.first], dis[p] + i.second);
		}
	}
}*/
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c = read(), n = read(), m = read(), d = read(), q = read(), k, a, u, v;
	ll T;
	vector<ll> t(m + 1);
	for (int i = 1; i <= m; i++) {
		t[i] = read();
	}
	G.resize(m + 1);
//	vector<vector<int>> f[2];
//	f[0].assign(n + 1, vector<int> (n + 1));
//	f[1].assign(n + 1, vector<int> (n + 1));
	int Last;
	for (int i = 1; i <= n; i++) {
		k = read();
		for (int j = 1; j <= k; j++) {
			a = read(), T = read();
			G.push_back({});
			G.back().push_back({a, T});
			G[a].push_back({G.size() - 1, T});
			if (j != 1) G[Last].push_back({G.size() - 1, 0}), G.back().push_back({Last, 0});
			Last = G.size() - 1;
		}
	}
	n = G.size();
	vector<vector<ll>> f[2];
	f[0].assign(n, vector<ll> (n, 5e12));
	f[1].assign(n, vector<ll> (n, 5e12));
//	for (int i = 1; i < G.size(); i++) {
//		cout << i << ':';
//		for (auto &j : G[i]) {
//			cout << j.first << ' ';
//		}
//		cout << '\n';
//	}
	//dis.resize(G.size());
	for (int i = 1; i < n; i++) {
		for (auto &j : G[i]) {
			f[0][i][j.first] = min(f[0][i][j.first], j.second);
		}
	}
//	for (int j = 1; j < n; j++) {
//		for (int k = 1; k < n; k++) {
//			cout << j << ' ' << k << ' ' << f[n & 1 ^ 1][j][k] << '\n';
//		}
//	}
	for (int i = 1; i < n; i++) {
		f[1][i][i] = f[0][i][i] = 0;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			for (int k = 1; k < n; k++) {
				if (j == k) continue;
				f[i & 1][j][k] = min(f[i & 1 ^ 1][j][k], f[i & 1 ^ 1][j][i] + f[i & 1 ^ 1][i][k]);
			}
		}
	}
//	for (int j = 1; j < n; j++) {
//		for (int k = 1; k < n; k++) {
//			cout << j << ' ' << k << ' ' << f[n & 1 ^ 1][j][k] << '\n';
//		}
//	}
	while (q--) { 
		u = read(), v = read();
		write(f[n & 1 ^ 1][u][v] + t[u] + t[v]), putchar('\n');
//		for (int i = 1; i < dis.size(); i++) {
//			cout << dis[i] << ' ';
//		}
//		cout << '\n';
	}
}

