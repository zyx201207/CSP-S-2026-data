#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 10;
ll a[N];

inline ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x *= 10;
		x += ch - '0';
		ch = getchar();
	}
	return x * f;
}

void solve4() {
	ll n = read(), d = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	if (n == 1) {
		printf("0\n");
		return ;
	}
	ll dis = a[2] - a[1];
	ll k = d / dis;
	ll x = k + k;
	if (n >= x && k > 1) printf("%lld\n", n - x + 1);
	else printf("0\n");
}

void solve5() {
	ll n = read(), d = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	if (n == 1) {
		printf("0\n");
		return ;
	}
	int top = 1;
	while (top < n && a[top + 1] - a[1] <= d) top++;
	if (top == n) printf("0\n");
	else {
		int ans = 0;
		for (int i = n; i >= 1; i--) {
			if (a[i] - a[top - 1] <= d) {
				if (a[i] - a[top - 2] > d) ans++;
			}
		}
		printf("%lld\n", ans);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = read(), T = read();
	while (T--) {
		if (c >= 11 && c <= 12) solve4();
		else if (c >= 13 && c <= 14) solve5();
	}
	return 0;
}
