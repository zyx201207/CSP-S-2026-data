#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
int n;
ll m;
ll a[N], sum[N];
int check (int x) {
	ll res = (1ll << 60);
	for (int i = x; i <= n; i++) {
		ll c = x * a[i] - (sum[i] - sum[i - x]);
		res = min (res, c);
	}
	return res <= m;
}
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
	}
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	ll l = 0, r = N;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check (mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	printf ("%lld\n", l);
	return 0;
}
