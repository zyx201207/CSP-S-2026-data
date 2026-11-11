#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;

const int N = 5e5 + 10;
int n; ll m, a[N], d[N], pre[N], sum[N], ans;

ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

void write(ll x) {
	if (x < 0) {
		putchar('-');
		x *= -1;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}

ll calc(ll l, ll r) {
	ll val1 = (r - l) * sum[r];
	ll val2 = pre[r - 1] - pre[l - 1];
	return val1 - val2;
}

int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i ++) {
		d[i] = a[i] - a[i - 1];
		sum[i] = sum[i - 1] + d[i];
		pre[i] = pre[i - 1] + sum[i];
	}
	for (int i = 1; i <= n; i ++) {
		int l = 1, r = i, res = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (calc(mid, i) <= m) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		ll now = i - res + 1;
		ans = max(ans, now);
	}
	write(ans); putchar('\n');

	return 0;
}
