#include <bits/stdc++.h>
#define fst first 
#define scd second
using namespace std;
using ll = long long;
using pr = pair<int, int>;
constexpr int N = 5e5 + 10;
constexpr ll oo = 1e18;
inline ll rd() {
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
	return x * f;
}
int c, t, n, dp[N];
ll d, a[N], ans;
int val[N << 2], cnt[N << 2];
void pushup(int p) {
	val[p] = min(val[lc(p)], val[rc(p)]);
	if (val[p] == val[lc(p)]) cnt[p] += cnt[lc(p)];  
	if (val[p] == val[rc(p)]) cnt[p] += cnt[rc(p)];  
}
void build(int p, int l, int r) {
	if (l == r) {
		val[p] = oo;
		cnt[p] = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(lc(p), l, mid), build(rc(p), mid + 1, r);
}
void insert(int p, int l, int r, int x, int v, int c) {
	if (l == r) return val[p] = v, cnt[p] = c, void();
	int mid = l + r >> 1;
	x <= mid ? insert(lc(p), l, mid, x, v, c) : insert(rc(p), mid + 1, r, x, v, c);
	pushup(p);
}
pr cmp(pr x, pr y) {
	if (x.fst == y.fst) return (x.fst)
}
pair<int, int> query(int p, int l, int r, int ql, int qr) {
	if (ql > r || l > qr) return {oo, 0};
	if (ql <= l && r <= qr) return {val[p], cnt[p]};
	int mid = l + r >> 1;
	auto x = query(lc(p), l, mid, ql, qr);
	auto y = query(rc(p), mid + 1, r, ql, qr)
	return 
}
int main() {
	//freopen("migrate3.in", "r", stdin);
	c = rd(), t = rd();
	if (c <= 10) {
		while (t--) {
			n = rd(), d = rd();
			ans = 0; 
			for (int i = 1; i <= n; i++) a[i] = rd();
			for (int i = 1; i <= n; i++) {
				if (a[i] > 0) {
					ll l = a[i] - d, r = (a[i] - 1) / d * d;
					st[i] = lower_bound(a + 1, a + n + 1, l) - a;
					ed[i] = upper_bound(a + 1, a + n + 1, r) - a - 1;
				}
				else {
					ll l = a[i] - d, r = (a[i] / d - 1) * d;
					st[i] = lower_bound(a + 1, a + n + 1, l) - a;
					ed[i] = upper_bound(a + 1, a + n + 1, r) - a - 1;					
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) dp[j] = sum[j] = 0;
				dp[i] = 1, sum[i] = 1;
				for (int j = i + 1, l, r; j <= n; j++) {
					dp[j] = sum[ed[j]] - sum[st[j] - 1];
					if (dp[j] == 2) ans++;
					if (dp[j] >= 2) dp[j] = 2;
					sum[j] = (dp[j] + sum[j - 1]);
				}
			}
			cout << ans << '\n';
		}
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 3
0 3 6 7 8 9 10 13 16 19
*/
