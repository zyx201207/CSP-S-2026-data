#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int C, T, n;
ll a[2000010], d;
int l[2000010], r[2000010];

ll read() {
	char ch = getchar();
	ll f = 1, k = 0;
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		k = k * 10 + ch - '0';
		ch = getchar();
	}
	return f * k;
}

int main() {
	freopen("migrate.in", "r", stdin);
//	freopen("migrate5.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	C = read(), T = read();
	for ( ; T-- ; ) {
		n = read(), d = read();
		for (int i = 1 ; i <= n ; i++) a[i] = read();
		a[0] = -5e18, a[n + 1] = 5e18;
		if (n == 1) {
			puts("0");
			continue;
		}
		if (C >= 11 && C <= 12) {
//		if (C == 0) {
			ll t = d / (a[2] - a[1]);
			if (t <= 1) puts("0");
			else {
				printf("%lld\n", max(0LL, n - t * 2 + 1));
			}
			continue;
		}
		l[0] = 1;
		for (int i = 1 ; i <= n ; i++) {
			l[i] = l[i - 1];
			while (a[i] - a[l[i]] > d) ++l[i];
		}
		r[n + 1] = n + 1;
		for (int i = n ; i ; i--) {
			r[i] = r[i + 1];
			while (a[r[i]] - a[i] > d) --r[i];
		}
		ll ans = 0;
		for (int i = 1 ; i <= n ; i++) {
			int p = r[r[i]], q = r[i], ls = i, v = 0;
			while (p <= n && q < p) {
				if (v + q - max(l[p], i) > 1) break;
				if (n > 5000 && q + v - 2 >= ls) ans += r[q + v - 1] - r[q + v - 2];
				else {
					for (int j = q + 1 ; j <= p ; j++)
						if (q - l[j] + v == 1) ++ans;
				}
				v += q - max(l[p], i);
				ls = q, q = p, p = r[p];
//				cout << i << " " << p << " " << q << " | " << ans << endl;
			}
//			cout << ans << endl;
		}
		printf("%lld\n", ans);
	}
	return 0;
} 

/*
0 1
10 3
0 3 6 7 8 9 10 13 16 19

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int C, T, n;
ll a[2000010], d;
int l[2000010], r[2000010];

ll read() {
	char ch = getchar();
	ll f = 1, k = 0;
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		k = k * 10 + ch - '0';
		ch = getchar();
	}
	return f * k;
}

int main() {
//	freopen("migrate.in", "r", stdin);
	freopen("migrate5.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	C = read(), T = read();
	for ( ; T-- ; ) {
		n = read(), d = read();
		for (int i = 1 ; i <= n ; i++) a[i] = read();
		a[0] = -5e18, a[n + 1] = 5e18;
		if (n == 1) {
			puts("0");
			continue;
		}
		if (C >= 11 && C <= 12) {
//		if (C == 0) {
			ll t = d / (a[2] - a[1]);
			if (t <= 1) puts("0");
			else {
				printf("%lld\n", max(0LL, n - t * 2 + 1));
			}
			continue;
		}
		l[0] = 1;
		for (int i = 1 ; i <= n ; i++) {
			l[i] = l[i - 1];
			while (a[i] - a[l[i]] > d) ++l[i];
		}
		r[n + 1] = n + 1;
		for (int i = n ; i ; i--) {
			r[i] = r[i + 1];
			while (a[r[i]] - a[i] > d) --r[i];
		}
		ll ans = 0;
		for (int i = 1 ; i <= n ; i++) {
			int p = r[r[i]], q = r[i], ls = i, v = 0;
			while (p <= n && q < p) {
				if (v + q - max(l[p], i) > 1) break;
				if (q + v - 2 >= ls) ans += r[q + v - 1] - r[q + v - 2];
//				else if (q + v - 2 - 1 == ls) ans += r[q + v - 1] - ls;
//				ans += r[q + v - 1] - r[q + v - 2];
				v += q - max(l[p], i);
				ls = q, q = p, p = r[p];
//				cout << i << " " << p << " " << q << " | " << ans << endl;
			}
//			cout << ans << endl;
		}
		printf("%lld\n", ans);
	}
	return 0;
} 

0 1
10 3
0 3 6 7 8 9 10 13 16 19
*/
