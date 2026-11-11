#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
int n, m;
ll a[N], dp[N][N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	memset(dp, 128, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] & a[i]);
		}
	printf("%lld\n", dp[n][m]);
	return 0;
}
