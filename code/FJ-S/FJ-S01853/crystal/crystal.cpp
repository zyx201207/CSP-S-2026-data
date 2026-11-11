#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll read () {
	ll w = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		w = w * 10 + c - '0';
		c = getchar();
	}
	return w * f;
}

const int mxn = 5e5 + 5;

ll a[mxn];
ll cf[mxn];

ll n, m;
ll ansl, ansr;

bool check (int x) {
	ll sum = 0;
	for (int i = 1; i < x; i++) {
		sum += a[x - 1] - a[i];
	}
	for (ll r = x; r <= n; r++) {
		ll l = r - x + 1;
		sum -= a[r - 1] - a[l - 1];
		sum += (a[r] - a[r - 1]) * (x - 1);
		if (sum <= m) return 1;
	}
	return 0;
}

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read();
	m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		cf[i] = a[i] - a[i - 1];
	}
	int ans = 0;
	ll l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	printf("%d ", ans);
	return 0;
}
