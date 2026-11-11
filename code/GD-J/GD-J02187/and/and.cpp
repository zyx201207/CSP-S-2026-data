#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int a[N];
int dp[2010][2010];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], dp[i][1] = a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			for (int k = i - j + 1; k < i; k++)
				dp[i][j] = max(dp[i][j], dp[k][j - 1] & a[i]);
//			cout << i << ' ' << j << ' ' << dp[i - 1][j] << ' ' << dp[i][j] << '\n';
		}
	cout << dp[n][m] << '\n';
	return 0;
}
