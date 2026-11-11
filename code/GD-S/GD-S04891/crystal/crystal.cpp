#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e5 + 5;
ll a[N], s[N], n, m;

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
	for (ll i = pos - 1; i >= 0; i--) putchar(buf[i] + 48);
}

ll ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	read(n), read(m);
	for (ll i = 1; i <= n; i++) {
		read(a[i]);
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	ll i = n, j = n;
	while (i >= 1) {
		if (s[j - 1] - s[i - 1] + m >= a[j] * (j - i)) {
			ans = max(ans, j - i + 1);
			i--;
		} else if (i == j) {
			i--;
		} else if (s[j - 1] - s[i - 1] + m < a[j] * (j - i)) {
			j--;
		}
	}
	write(ans);
	return 0;
}
