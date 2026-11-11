#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;
using LL = long long;
using pii = pair<int, int>;

constexpr int MAXN = 5e5, mod = 998244353;
inline void chmax(int &x, int val) { if (x < val) x = val; }
inline void chmin(int &x, int val) { if (x > val) x = val; }
inline void inc(int &x, int val) { (x += val) >= mod && (x -= mod); }
inline void dec(int &x, int val) { (x -= val) < 0 && (x += mod); }
inline void tim(int &x, int val) { (x *= val) %= mod; }

inline int qpow(int x, int y = mod - 2) {
	int res = 1;
	while (y) {
		if (y & 1) tim(res, x);
		tim(x, x), y >>= 1;
	}
	return res;	
}

int n, m, res, a[MAXN+5], s[MAXN+5];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	IOS;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	for (int i = 1, l, r, mid, ans; i <= n; ++i) {
		l = i, r = n, ans = i - 1;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (a[mid] * (mid - i + 1) - (s[mid] - s[i - 1]) <= m) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		chmax(res, ans - i + 1);
	}
	cout << res;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
