#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x; short f; char ch;
inline ll read() {
	x = 0, f = 1, ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f;
}
inline void write(int s) {
	if (s < 0) putchar('-'), s = -s;
	if (s > 9) write(s / 10);
	putchar(s % 10 + 48);
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = read();
	ll m = read();
	//ll l, r;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = read();
	}
	sort(a.begin(), a.end());
	int pos = 0, ans = 1;
	__int128 cnt = 0;
	for (int i = 1; i < n; i++) {
		cnt += (i - pos) * (__int128)(a[i] - a[i - 1]);
		while (cnt > m) cnt -= a[i] - a[pos], pos++;
		ans = max(ans, i - pos + 1);
	}
	write(ans);
}

