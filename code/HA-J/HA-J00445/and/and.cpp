#include <bits/stdc++.h>
using namespace std;

const int C = 2001;
int n, m, a[C], dp[C][C];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(dp, -128, sizeof(dp));
	for (int i = 1; i <= n; i++)
		dp[i][0] = (1 << 30) - 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i && j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] & a[i]);
		}
	printf("%d\n", dp[n][m]);
	return 0;
}
