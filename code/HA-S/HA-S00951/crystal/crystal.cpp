#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll read () {
	ll x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar ();
	}
	return x * f;
}

const int MAXN = 5 * 1e5 + 10;
ll n, m;
ll a[MAXN];
ll ans = 1;
bool flagA = 1, flagB = 1;
ll del;
ll c[MAXN];

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	n = read (), m = read ();
	for (int i = 1; i <= n; i++) {
		a[i] = read ();
		if (a[i] != i) flagA = 0;
		if (i == 2) del = a[i] - a[i - 1];
		else if (i > 2) {
			if (a[i] - a[i - 1] != del) flagB = 0;
		}
	}
	if (m == 0) {
		printf ("1");
		return 0;
	}
	
	if (flagA) {
		ll t = sqrt(m * 2);
		if (m * 2 < t * (t + 1)) printf ("%lld", t);
		else printf ("%lld", t + 1);
		return 0;
	}
	if (flagB) {
		del = a[2] - a[1];
		if (m < del) printf ("1");
		else {
			for (int i = 1; i <= n; i++) {
				if ((i * a[i] - i * del) / 2 > m) {
					printf ("%d", i - 1);
					break;
				}
			}
		}
		return 0;
	}
	
	sort (a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) 
		c[i] += c[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--) {
			ll t = c[i] - c[j - 1];
			if (t > m) break;
			if ((ll)(i - j + 1) <= ans) continue;
			ans = max (ans, (ll)(i - j + 1));
		}
	}
	printf ("%lld", ans);
	return 0;
}
//Far in the blue sky~
