#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
inline ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 0;
		}
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	if (f) {
		return x;
	}
	return -x;
}
inline void write(ll s) {
	if (s < 10) {
		putchar(s ^ 48);
		return ;
	}
	write(s / 10);
	putchar(s % 10 ^ 48);
}
const ll inf = 0x3f3f3f3f3f3f;
ll c, T, n, d, a[5005], x;
pii dp[5005][5005];
ll sum[5005][5005];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read();
	T = read();
	while (T--) {
		n = read();
		d = read();
		ll ans = 0;
		if (n == 1) {
			x = read();
			putchar('0');
			putchar('\n');
			continue;
		}
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			for (int j = i; j <= n; j++) {
				dp[i][j] = {0, 0};
				sum[i][j] = 0;
			}
		}
		for (int i = 1; i < n; i++) {
			dp[i][i] = {0, 1};
			sum[i][i] = 1;
			for (int j = i + 1; j <= n; j++) {
				int idx = lower_bound(a + i, a + j, a[j] - d) - a;
				if (idx == j) {
					break;
				}
				pii cx = {dp[i][idx].first + 1, 0};
				int idx2 = lower_bound(dp[i] + i, dp[i] + j, cx) - dp[i] - 1;
				dp[i][j].second = sum[i][idx2] - sum[i][idx - 1];
				dp[i][j].first = dp[i][idx].first + 1;
				if (dp[i][j].second == 2) {
					ans++;
				}
				sum[i][j] = sum[i][j - 1] + dp[i][j].second;
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
