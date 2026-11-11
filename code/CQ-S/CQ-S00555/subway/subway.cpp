#include<bits/stdc++.h>
// #define int long long
using namespace std;
const long long INF = 1000000000000000000ll;
int Caseid, n, m, d, q, w[500005];
long long dp[505][505];
vector<pair<int, int>> v[500005];
map<pair<int, int>, int> num;
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> Caseid >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++) {
		int len, station, tim;
		cin >> len;
		for (int j = 1; j <= len; j ++) {
			cin >> station >> tim;
			v[station].push_back({i, tim});
			num[{i, station}] = tim;
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			dp[i][j] = INF;
		}
		dp[i][i] = 0;
	}
	for (int i = 1; i <= m; i ++) {
		int len = v[i].size();
		for (int j = 0; j < len; j ++) {
			for (int k = 0; k < j; k ++) {
				int x = v[i][j].first, y = v[i][k].first;
				dp[x][y] = min(dp[x][y], 1ll * v[i][j].second + 1ll * v[i][k].second);
				dp[y][x] = dp[x][y];
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			for (int k = 1; k <= n; k ++) {
				dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
			}
		}
	}
	while (q --) {
		int x, y;
		cin >> x >> y;
		long long ans = INF;
		for (auto i : v[x]) {
			for (auto j : v[y]) {
				ans = min(ans, dp[i.first][j.first] + 1ll * num[{i.first, x}] + 1ll * num[{j.first, y}]);
			}
		}
		ans += 1ll * w[x] + 1ll * w[y];
		cout << ans << "\n";
	}
	cerr << "Time elapsed:" << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
