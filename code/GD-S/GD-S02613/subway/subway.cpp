#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	vector<int> w(m);
	vector<vector<pair<int, int>>> a(n + m);
	
	for (int& x : w) cin >> x;
	for (int i = 0; i < n ; i++) {
		int s;
		cin >> s;
		for (int j = 0; j < s; j++) {
			int x, t;
			cin >> x >> t;
			x--;
			a[i].emplace_back(n + x, t);
			a[n + x].emplace_back(i, t);
		}
	}
	
	vector<vector<long long>> utime(n, vector<long long>(n + m, 1LL << 60));
	for (int i = 0; i < n; i++) {
		utime[i][i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (pair<int, int> p : a[i]) {
			utime[i][p.first] = p.second;
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < a[i + n].size(); j++) {
			for (int k = 0; k < j; k++) {
				int da = a[i + n][j].first;
				int db = a[i + n][k].first;
				utime[da][db] = utime[db][da] = min(utime[db][da], utime[da][i + n] + utime[db][i + n]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			for (int k = 0; k < j; k++) {
				if (i == k) continue;
				utime[j][k] = utime[k][j] = min(utime[k][j], utime[j][i] + utime[k][i]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		long long ans = 1LL << 60;
		for (pair<int, int> p : a[n + x]) {
			int i = p.first;
			long long tt = utime[i][n + x];
			for (int j = 0; j < n; j++) {
				ans = min(tt + utime[i][j] + utime[j][n + y], ans);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
