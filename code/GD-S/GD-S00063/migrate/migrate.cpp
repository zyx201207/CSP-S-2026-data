#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mk make_pair
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;
const int N = 2e6 + 10, inf = 1e18, M = 5e5 + 10;
int cid, T, n, D, a[N];
void work_A() {
	if(n == 1) return cout << "0\n", void();
	int del = a[2] - a[1], gap = D / del;
	if(gap <= 1) return cout << "0\n", void();
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(n - i + 1 >= 2 * gap) ans++;
	}
	cout << ans << "\n";
}
void work_B() {
	// a[1] -- a[n] <= 2gap
	int ans = 0, spc = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] - a[1] <= D) spc = i;
	}
	for(int i = spc + 1; i <= n; i++) {
		int l = 1, r = i, pos = 1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(a[i] - a[mid] <= D) pos = mid, r = mid - 1;
			else l = mid + 1;
		}
		if(pos < spc) ans++; 
	}
	cout << ans << "\n";
}
int dp[N];
struct Info {
	int mn, cnt;
	Info friend operator + (const Info &a, const Info &b) {
		Info res; res.mn = min(a.mn, b.mn);
		if(res.mn == a.mn) res.cnt = a.cnt;
		if(res.mn == b.mn) res.cnt += b.cnt;
		return res;
	} 
};
#define lson u << 1, l, mid
#define rson u << 1 | 1, mid + 1, r
struct seg_tree {
	Info info;
}tr[N * 8];
void build(int u, int l, int r) {
	tr[u].info = {inf, 0};
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(lson), build(rson);
	tr[u].info = tr[u << 1].info + tr[u << 1 | 1].info;
}
void upd(int u, int l, int r, int p, int x, int c) {
	if(l == r) return tr[u].info = {x, c}, void();
	int mid = (l + r) >> 1;
	if(p <= mid) upd(lson, p, x, c);
	else upd(rson, p, x, c);
	tr[u].info = tr[u << 1].info + tr[u << 1 | 1].info;
}
Info query(int u, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return tr[u].info;
	int mid = (l + r) >> 1; Info res = {inf, 0};
	if(ql <= mid) res = res + query(lson, ql, qr);
	if(mid < qr) res = res + query(rson, ql, qr);
	return res; 
}
void brute() {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) dp[j] = inf;
		dp[i] = 0; build(1, i, n);
		upd(1, i, n, i, 0, 1);
//		cout << "---------------- " << i << " -------------------\n";
		for(int j = i + 1; j <= n; j++) {
			int l = i, r = j, pos = j;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(a[j] - a[mid] <= D) pos = mid, r = mid - 1;
				else l = mid + 1;
			}
//			for(int k = pos; k < j; k++) {
//				if(dp[k] + 1 < dp[j]) dp[j] = dp[k] + 1, cnt[j] = cnt[k];
//				else if(dp[k] + 1 == dp[j]) cnt[j] += cnt[k];
//			}
			Info res = query(1, i, n, pos, j - 1);
			ans += (res.cnt == 2); dp[j] = res.mn + 1;
			upd(1, i, n, j, dp[j], res.cnt);
//			cout << j << " " << pos << "\n";
//			if(cnt[j] == 2) cout << "got it " << i << " " << j << "\n";
		}
//		for(int j = i; j <= n; j++) cout << dp[j] << " ";
//		cout << "\n";
	}
	cout << ans << "\n";
}
void solve() {
	cin >> n >> D;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(cid == 11 || cid == 12) return work_A();
//	if(cid == 13 || cid == 14) return work_B();
	if(cid <= 10) return brute();
	brute();
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> cid >> T;
	while(T--) solve();
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
