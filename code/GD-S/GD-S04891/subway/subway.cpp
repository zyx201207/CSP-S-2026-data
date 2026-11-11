#include <bits/stdc++.h>
using namespace std;
// 1~11
typedef long long ll;
const int N = 505, M = 1e3 + 5, D = 25;
const ll INF = LONG_LONG_MAX;
ll c, n, m, d, q;
ll w[M], t[M][D]; // w:timeINOUT, t:timeININOUTOUT, a:subwayToStation
ll a[N][M];
ll k[M], dpos[M];

void read(ll &x) {
	x = 0;
	ll w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - 48;
		ch = getchar();
	}
	x *= w;
}

void write(ll x) {
	if (x == 0) {
		putchar('0');
		return;
	} else if (x < 0) {
		putchar('-');
		x = -x;
	}
	ll buf[100] = {0}, pos = 0;
	while (x > 0) buf[pos++] = x % 10, x /= 10;
	for (int i = pos - 1; i >= 0; i--) putchar(buf[i] + 48);
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read(c), read(n), read(m), read(d), read(q);
	for (ll i = 1; i <= m; i++) read(w[i]);
	for (ll i = 1; i <= n; i++) {
		read(k[i]);
		for (ll j = 1; j <= k[i]; j++) {
			ll x;
			read(a[i][j]), read(x);
//			t[a[i][j]][++dpos[i]] = x;
//			sub[a[i][j]][dpos[i]] = i;
			//if (Find(a[i][j]) != Find(a[i][1])) Union(a[i][j], a[i][1]);
		}
	}
	while (q--) {
		ll x, y;
		read(x), read(y);
		write(w[x] + w[y] + 2);
		cout << endl;
	}
	return 0;
}
