/*或许是不知梦的缘故 流离之人追逐幻影*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;

#define Floyd main

ll inline read () {
	ll x = 0, f = 1;
	scanf("%lld", &x);
	return x * f;
}

void inline write (ll x) {
	printf("%lld", x);
	return void ();
}

ll n, m, energy[N], S[N], ans = 1;

inline ll MAX (ll x, ll y) {return x > y ? x : y;}

void inline solve () {
	n = read(),  m = read();
	for (int i = 1; i <= n; ++i) energy[i] = read();
	sort (energy + 1, energy + n + 1);
	for (int i = 1; i <= n; ++i) S[i] = S[i - 1] + energy[i];
	ll L = 0;
	for (ll r = 1; r <= n; ++r) {
		ll Now = (r - L) * 1ll * energy[r];
		while (Now > S[r] - S[L] + m) L++, Now -= energy[r];
		ans = MAX (ans, r - L);
	}
	write (ans), putchar ('\n');
	return void ();
}

signed Floyd () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll T = 1;
	while (T--) solve ();
	return 0;
}
