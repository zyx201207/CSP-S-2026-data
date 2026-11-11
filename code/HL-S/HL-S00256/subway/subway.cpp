#include <bits/stdc++.h>
//define int long long
using namespace std;
const int N = 1010;
int c, n, m, d, q;
int w[N], dp[N][N], k[N], a[N][N], t[N][N];
void solve()
{
	memset(dp, 0x3f, sizeof dp);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++ )
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++ )
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++ )
		{
			cin >> a[i][j] >> t[i][j];
			for (int kk = 1; kk <= j - 1; kk ++ )
			{
				dp[a[i][kk]][a[i][j]] = min(dp[a[i][kk]][a[i][j]], t[i][j] + t[i][kk]);
				dp[a[i][j]][a[i][kk]] = min(dp[a[i][j]][a[i][kk]], t[i][j] + t[i][kk]);
			}
		}
	}
	for (int k = 1; k <= m; k ++ )
	{
		for (int i = 1; i <= m; i ++ )
		{
			for (int j = 1; j <= m; j ++ )
			{
				dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
//				cout << dp[i][j] << ' ';
			}
//			cout << '\n';
		}
//		cout << '\n';
	}
			
	while (q -- )
	{
		int x, y;
		cin >> x >> y;
		cout << dp[x][y] + w[x] + w[y] << '\n';
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}

