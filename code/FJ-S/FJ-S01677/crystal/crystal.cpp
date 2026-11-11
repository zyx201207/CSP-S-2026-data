#include <bits/stdc++.h>
using namespace std;

inline long long read(void) {
	long long x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - 48, c = getchar();
	return x * f;
}

long long n, m, a[500005], ans;

int main(void) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + 1 + n);
	long long t = 1, sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		while (a[i] * (i - t + 1) - sum > m) sum -= a[t++];
		ans = max(ans, i - t + 1);
	}
	printf("%lld", ans);
	return 0;
}
