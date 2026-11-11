#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 10;
constexpr ll oo = 1e18;
inline ll rd() {
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, ans;
ll a[N], s[N], m;
ll query(int l, int r) {
	return s[r] - s[l - 1];
}
bool check(int i, int mid) {
	ll val = oo;
	if (i - mid < 1) return false;
	ll x = mid * a[i] - query(i - mid, i - 1);
	// cout << x << ' ' << y << '\n';
	val = min(val, x);
	return val <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = rd(), m = rd();
	for (int i = 1; i <= n; i++) a[i] = rd();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = n;
		while (l <= r) {
			if (r <= ans) break;
			int mid = l + r >> 1;
			if (check(i, mid)) ans = max(ans, mid), l = mid + 1;
			else r = mid - 1;
		}
	}
	cout << ans + 1 << '\n';
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
