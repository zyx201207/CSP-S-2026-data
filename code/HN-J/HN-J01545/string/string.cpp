#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(s)	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
const int N = 2e5 + 10;
char ch[N];
int n;
ll a[N];
int get(ll x) {
	return lower_bound(a + 1, a + 1 + n, x) - a;
}
signed main() {
	file(string);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> ch[i];
		a[i] += a[i - 1];
	}
	ll ans = 0;
	ll L = 1, R = a[n];
	while (get(L) < get(R)) {
		int gL = get(L), gR = get(R);
		ll len = min(a[gL] - L + 1, R - a[gR - 1]);
		if (ch[gL] != ch[gR])	ans += len;
		L += len, R -= len;
	}
	cout << ans;
	return 0;
}
