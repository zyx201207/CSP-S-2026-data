#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, n, m, d, q, w[500005], dst[505][505], tmp[500005];
pair<int, int> edges[500005][25];
int tot[500005];
signed main() {
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; ++i) cin >> w[i];
	memset(dst, 15, sizeof(dst));
	for (int i = 1; i <= m; ++i) {
		dst[i][i] = 0;
		int k;
		cin >> k;
		while (k--) {
			int a, t;
			cin >> a >> t;
			for (int _ = 0; _ < tot[a]; ++_) {
				auto j = edges[a][_];
				dst[j.first][i] = min(dst[j.first][i], t + j.second);
				dst[i][j.first] = min(dst[i][j.first], t + j.second);
			}
			edges[a][tot[a]++] = make_pair(i, t);
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = 1; k <= m; ++k) {
				dst[j][k] = min(dst[j][k], dst[j][i] + dst[i][k]);
			}
		}
	}
	memset(tmp, 15, sizeof(tmp));
	for (int i = 1; i <= q; ++i) {
		int x, y;
		cin >> x >> y;
		int ans = 1ll << 60;
		for (int _ = 0; _ < tot[x]; ++_) {
			for (int __ = 0; __ < tot[y]; ++__) {
				auto j = edges[x][_], k = edges[y][__];
				ans = min(ans, j.second + k.second + dst[j.first][k.first]);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
