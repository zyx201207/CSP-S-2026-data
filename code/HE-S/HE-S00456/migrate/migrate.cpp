#include<bits/stdc++.h>
#define int long long
#define debug puts("\n--------------")
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

inline int read() {
	int x = 0, k = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') k = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * k;
}

inline void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + '0');
	return;
}

const int N = 2e6 + 50;
int n, d, ans;
int a[N];
int dp[N];
int dp_ci[N];

inline void del(int x) {
	for (int i = x; i <= n; ++i) {
		dp[i] = inf;
		dp_ci[i] = 1;
	}
	dp[x] = 0;

	for (int i = x + 1; i <= n; ++i) {
		for (int j = i - 1; j >= x && a[i] - a[j] <= d; --j) {
			if (dp[i] > dp[j] + 1) {
				dp[i] = dp[j] + 1;
				dp_ci[i] = dp_ci[j];
			}
			else if (dp[i] == dp[j] + 1) dp_ci[i] += dp_ci[j];
		}
	}
	
	for (int i = x; i <= n; ++i) {
		if (dp_ci[i] == 2) ++ans;
	}
	return;
}

inline void solve() {
	n = read(), d = read(), ans = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}
	for (int i = 1; i <= n; ++i) {
		del(i);
	}
	write(ans);
	putchar('\n');
	return;
}

int32_t main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = read(), T = read();
	while (T--) {
		solve();
	}
	return 0;
}
