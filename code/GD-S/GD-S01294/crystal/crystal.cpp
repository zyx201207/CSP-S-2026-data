#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N = 5e5 + 10;
ll a[N], ans, n, m, s[N];
ll read(ll x = 0, ll f = 1) {
	char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') {
		f *= -1, c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
void write(ll x) {
	string s = to_string(x);
	for (int i = 0; i < int(s.size()); i++) putchar(s[i]);
	return;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	ans = 1;
	a[n + 1] = 1e12 + 10;
	for (int i = 1; i <= n; i++) {	
		s[i] = s[i - 1] + a[i];
	}
	ll l = 1;
	for (int i = 2, j = 0; i <= n; i++) {
		while (((i - l + 1) * a[i] - s[i] + s[l - 1]) > m) l++;
		ans = max(ans, i - l + 1);
	}
	write(ans);
	return 0;
}
