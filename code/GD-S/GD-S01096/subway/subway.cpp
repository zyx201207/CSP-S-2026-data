#include <bits/stdc++.h>
#define pb push_back
#define int long long 

using namespace std;

const int maxn = 5e2 + 10, maxm = 5e5 + 10, inf = 1e18;

int c, n, m, d, q;
int w[maxm];
struct node {
	int v, w;
	bool operator < (const node &o) const {
		return w > o.w;
	}
};
vector<node> e[(maxm + maxn) << 1];
int f[maxn][maxn];

int dd(int x, int y) {
	int res = inf, v1, v2, w1, w2;
	for (auto ed1: e[x]) {
		v1 = ed1.v, w1 = ed1.w;
		for (auto ed2: e[y]) {
			v2 = ed2.v, w2 = ed2.w;
			res = min(res, w1 + f[v1 - m][v2 - m] + w2);
		}
	}
	return res;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			f[i][j] = inf;
		f[i][i] = 0;
	}
	for (int i = 1; i <= m; ++i) 
		cin >> w[i];
	for (int i = 1, k, x, t; i <= n; ++i) {
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			cin >> x >> t;
			e[i + m].pb({x, t});
			e[x].pb({i + m, t});
		}
	} 
	for (int i = 1, u, v, v1, w1, w2; i <= n; ++i) {
		u = i + m;
		for (auto ed1: e[u]) {
			v1 = ed1.v, w1 = ed1.w; 
			for (auto ed2: e[v1]) {
				v = ed2.v, w2 = ed2.w;
				if (u == v) continue;
				f[u - m][v - m] = f[v - m][u - m] = w1 + w2;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (int i = 1, x, y, res; i <= q; ++i) {
		cin >> x >> y;
		cout << w[x] + dd(x, y) + w[y] << '\n';
	}
	return 0;
}
