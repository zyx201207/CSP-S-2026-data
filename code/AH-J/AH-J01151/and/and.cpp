#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], dp[2005][2005];
int main ()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			dp[i][j] = max(dp[i - 1][j], (max(dp[i][j - 1], dp[i - 1][j - 1]) & a[j]));
	cout << dp[n][m];
	return 0;
}
