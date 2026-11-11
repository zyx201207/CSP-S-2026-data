#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 5e5 + 5;
pair <int, long long> a[M][25];
long long d[N][N], w[M], k[N], cnt[M];

inline long long solve(int x, int y) {
	long long ans = 1e15 + 7;
	for (int i = 1; i <= cnt[x]; i++)
		for (int j = 1; j <= cnt[y]; j++) {
			if (a[x][i].first == a[y][j].first)
				ans = min(ans, a[x][i].second + a[y][j].second);
			ans = min(ans, a[y][j].second + a[x][i].second + d[a[x][i].first][a[y][j].first]);
		}
	return ans + w[x] + w[y];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, n, m, d1, q;
	cin >> c >> n >> m >> d1 >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (long long j = 1, g, t; j <= k[i]; j++) {
			cin >> g >> t;
			a[g][++cnt[g]] = {i, t};
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = 1e15 + 7;
	for (int i = 1; i <= n; i++)
		d[i][i] = 0;
	for (int i = 1; i <= m; i++)
		if (cnt[i] > 1)
			for (int j = 1; j <= cnt[i]; j++)
				for (int k = j + 1; k <= cnt[i]; k++) {
					d[a[i][j].first][a[i][k].first] = min(d[a[i][j].first][a[i][k].first], a[i][j].second + a[i][k].second);
					d[a[i][k].first][a[i][j].first] = min(d[a[i][k].first][a[i][j].first], a[i][j].second + a[i][k].second);
				}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					d[j][i] = min(d[i][j], d[j][i]);
					d[i][j] = min(d[i][j], d[j][i]);
				}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}
}
