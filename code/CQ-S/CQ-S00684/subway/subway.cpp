#include<bits/stdc++.h>
#define ls (x << 1)
#define rs (x << 1 | 1)
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int N = 2e4 + 5;
const db EPS = 1e-6;
const int MOD = 998244353;
const ull P = 33550337;

inline int lowbit(int x) {
	return (x & (-x));
}

ll c, n, m, d, q;
ll W[N], a[505][N], t[505][N], idx[505][N];
ll g[505][505], dist[505][505];
vector<int> stn[N];

inline void Floyd() {
	memset(dist, 0x3f, sizeof(dist));
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		for (int j = 1; j <= n; j++) {
			if (!g[i][j]) continue;
			dist[i][j] = g[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << dist[i][j] << " ";
//		}
//		cout << "\n";
//	}
	return;
}

inline int query(int U, int V) {
	ll res = LLONG_MAX;
	for (auto u : stn[U]) {
		for (auto v : stn[V]) {
			res = min(res, t[u][idx[u][U]] + dist[u][v] + t[v][idx[v][V]]);
		}
	}
	return res;
}

// 地铁是双向任意通行  
int main() {
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
//	memset(g, 0x3f, sizeof(g));
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> W[i];
	}
	for (int i = 1; i <= n; i++) {
		int k = 0;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
			stn[a[i][j]].push_back(i);
			idx[i][a[i][j]] = j;
		}
	}
//	for (int i = 1; i <= m; i++) {
//		cout << i << ": ";
//		for (auto ash : stn[i]) {
//			cout << ash << " ";
//		}
//		cout << "\n";
//	}
	// O(k * d^2)
	for (int i = 0; i < m; i++) {
		if (stn[i].size() < 2) continue;
		for (int U = 0; U < stn[i].size(); U++) {
			for (int V = U + 1; V < stn[i].size(); V++) {
//				cout << "U == " << U << "; V == " << V << "\n";
				int u = stn[i][U], v = stn[i][V];
				ll w = t[u][idx[u][i]] + t[v][idx[v][i]];
				if (g[u][v]) g[u][v] = min(g[u][v], w);
				else g[u][v] = w;
				if (g[v][u]) g[v][u] = min(g[v][u], w);
				else g[v][u] = w;
//				cout << u << " <--> " << v << " : " << g[u][v] << "\n";
			}
		}
	}
	
	Floyd();
	
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << W[u] + W[v] + query(u, v) << "\n";
	}
	
	return 0;
}
