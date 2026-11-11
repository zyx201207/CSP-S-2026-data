#include <bits/stdc++.h>
using namespace std;

short int c, n, d;
int m, q, x, y;
vector<int> w, k;
vector<vector<int>> a, t;
vector<vector<long long>> dp;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	w.resize(m + 5);
	k.resize(n + 5);
	a.resize(n + 5);
	t.resize(n + 5);
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i].resize(k[i] + 5);
		t[i].resize(k[i] + 5);
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j],
			cin >> t[i][j];
	}
	dp.resize(m + 5);
	for (int i = 1; i <= m; i++) {
		dp[i].resize(m + 5);
		for (int j = 1; j <= m; j++)
			dp[i][j] = w[i] + w[j] + t[i][j] + t[j][i];
	}
	for (int k = 1; k <= m; k++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	for (int i = 1; i <= q; i++)
		cin >> x >> y,
		cout << dp[x][y] << '\n';
	return 0;
}
