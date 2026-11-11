#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int c, n, m, d, q, k[510], w[500010];
vector<int> a[500010], t[500010], vec[500010];

bool check(int x, int y) { 
	for (int i = 1; i <= k[y]; i++) if (a[y][i] == x) {
		return true;
	}
	return false;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		a[i].resize(k[i] + 10);
		t[i].resize(m + 10);
		for (int j = 1; j <= k[i]; j++) {
			scanf("%d", &a[i][j]);
			scanf("%d", &t[i][a[i][j]]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			vec[a[i][j]].push_back(i);
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = (ll)1e18;
		for (auto i : vec[x]) { // 1
			for (int l = 1; l <= k[i]; l++) {
				int j = a[i][l];
				if (j != y) continue;
				ans = min(ans, (ll)w[x] + t[i][x] + t[i][y] + w[y]);
			}
		}
		for (auto i : vec[x]) { // 2
			for (int j = 1; j <= m; j++) if (check(j, i)) {
				for (auto l : vec[j]) if (check(y, l)) {
					ans = min(ans, (ll)w[x] + t[i][x] + t[i][j] + t[l][j] + t[l][y] + w[y]);
				}
			}
		}
		for (auto i : vec[x]) { // 3
			for (int j = 1; j <= m; j++) if (check(j, i)) {
				for (auto l : vec[j]) {
					for (int p = 1; p <= m; p++) if (check(p, l)) {
						for (auto r : vec[p]) if (check(y, r)) {
							ans = min(ans, (ll)w[x] + t[i][x] + t[i][j] + t[l][j] + t[l][p] + t[r][p] + t[r][y] + w[y]);
						}
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

