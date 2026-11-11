#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 5001;

int n, m, ans, a[N], dp[N][N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); dp[i][1] = a[i]; }
	for (int i = 2; i <= m; i++) for (int j = 1; j <= n; j++) {
		for (int p = 1; p < j; p++) dp[j][i] = max(dp[j][i], a[j] & dp[p][i - 1]);
		if (i == m) ans = max(ans, dp[j][i]);
	} printf("%d", ans);
	return 0;
}

