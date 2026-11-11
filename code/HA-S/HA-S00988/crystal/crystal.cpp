#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n, ans;
ll m, mx;
ll a[N], c[N];
ll solve(int x, int y) {
	ll res = 0x3f;
	int p = x - y + 1;
	int q = x;
	if (p <= 0) {
		p = 1;
		q = y;
	}
	while (p <= x && q <= n) {
		int cnt = 0;
		ll tmp[n] = {};
		tmp[p] = c[p];
		for (int i = p; i <= q; i++) {
			tmp[i] = tmp[i - 1] + c[i];
		}
		ll sum = 0;
		for (int i = p; i <= q; i++) {
			sum += tmp[i];
		}
		res = min(res, sum + cnt);
		p++;
		q++;
	}
	return res;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; i++) c[i] = a[i + 1] - a[i];
	ans = 1;
	ll dp[n + 1][n + 1];
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		if (i != n && c[i] == 0) cnt++;
		for (int j = 2; j <= n; j++) {
			dp[i][j] = solve(i, j - 1);
			if (dp[i][j] <= m) {
				ans = max(ans, j + cnt);
			}
		}
	}
	printf("%d", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
