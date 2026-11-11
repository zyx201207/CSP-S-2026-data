#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e5 + 9;

inline ll read();

ll n, m, a[N], ans = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1, j = 2, tm = m; j <= n; j++) {
		tm -= (j - i) * (a[j] - a[j - 1]);
		while (tm < 0) {
			tm += a[j] - a[i++];
		}
		ans = max(ans, j - i + 1);
	}
	printf("%lld", ans);
	return 0;
}

inline ll read() {
	ll w = 0, f = 1, c = getchar();
	while (!isdigit(c)) {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (isdigit(c)) {
		w = w * 10 + (c ^ 48);
		c = getchar();
	}
	return w * f;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
