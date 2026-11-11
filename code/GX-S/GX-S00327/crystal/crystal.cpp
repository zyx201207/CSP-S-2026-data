#include <bits/stdc++.h>
#define ll long long
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
ll n, m, a[5000005], sum[5000005], res;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 2; i <= n; i++) {
		ll l = 1, r = i - 1, ans = 0;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			ll k = a[i] * mid;
			if (k - sum[i - 1] + sum[i - mid - 1] <= m) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		res = max(res, ans);
	}
	res++;
	cout << res;
	return 0;
}
