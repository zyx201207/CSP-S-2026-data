#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int c, n, m, d, q;
vector<int> w;
vector<vector<int>> a;
vector<vector<int>> t;

vector<vector<ll>> f;

void buildGraph() {
	// 线路 
	for (int i = 0; i < a.size(); i++) {
		// 站点 
		for (int j = 0; j < a[i].size() - 1; j++) {
			// 该站点后面的站点（路线上）
			for (int k = 1; j + k < a[i].size(); k++) {
				int u = a[i][j];
				int v = a[i][j + k];
				int w = t[i][j] + t[i][j + k];
				f[u][v] = w;
				f[v][u] = w;
			}
		}
	}
}

void floyd() {
	for (int i = 0; i <= m; i++) {
		f[i][i] = 0;
	}
	
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	w.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	
	a.resize(n);
	t.resize(n);
	for (int i = 0; i < n; i++) {
		int k, ai, ti;
		cin >> k;
		a[i].resize(k);
		t[i].resize(k);
		for (int j = 0; j < k; j++) {
			cin >> ai >> ti;
			a[i][j] = ai;
			t[i][j] = ti;
		}
	}
	
	f.resize(m + 1, vector<ll>(m + 1, LONG_LONG_MAX / 2LL));
	buildGraph();
	floyd();
	
	int sp, dp;
	for (int i = 0; i < q; i++) {
		cin >> sp >> dp;
		
		ll ans = w[sp - 1] + w[dp - 1] + f[sp][dp];
		cout << ans << '\n';
	}
	
	return 0;
}
