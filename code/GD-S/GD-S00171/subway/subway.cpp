#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;

const int N = 505;
const ll inf = 1ll << 60;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int c, n, m, d, q;
	std::cin >> c >> n >> m >> d >> q;
	
	std::vector<int> w(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> w[i];
	}
	
	std::vector<std::vector<pii>> v(m + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		std::cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			std::cin >> a >> t;
			v[a].push_back(std::make_pair(i, t));
		}
	}
	
	std::array<std::array<ll, N>, N> f;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) f[i][j] = inf;
		}
	}
	
	for (int i = 1; i <= m; i++) {
		int siz = v[i].size();
		for (int j = 0; j < siz; j++) {
			for (int k = j + 1; k < siz; k++) {
				int x = v[i][j].first, y = v[i][k].first;
				f[x][y] = std::min(f[x][y], (ll)(v[i][j].second + v[i][k].second));
				f[y][x] = std::min(f[y][x], (ll)(v[i][j].second + v[i][k].second));
			}
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (f[i][k] == inf) continue;
			for (int j = 1; j <= n; j++) {
				if (f[k][j] == inf) continue;
				f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		
		ll ans = inf;
		for (auto& a : v[x]) {
			for (auto& b : v[y]) {
				ans = std::min(ans, a.second + f[a.first][b.first] + b.second);
			}
		}
		
		ans = w[x] + ans + w[y];
		std::cout << ans << "\n";
	}
	return 0;
}
