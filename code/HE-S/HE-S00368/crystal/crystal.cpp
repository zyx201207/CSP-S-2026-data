#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], diff[N], dp[N], sum = 0;
int maxn = 0;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cin >> a[i], diff[i] = a[i] - a[i - 1], dp[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (2 * diff[i] + sum > m) {
			sum = 0, dp[i] = 1;
		} else {
			dp[i] = dp[i - 1] + (2 * diff[i] + sum <= m);
			sum = diff[i] + sum, maxn = max(dp[i], maxn);
		}
	}
	printf("%d\n", maxn);
	return 0;
}
