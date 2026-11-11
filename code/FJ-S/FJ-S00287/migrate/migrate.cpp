#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, T, n, d, X[2000002], r[2000002], dep[2000002], ans, col[2000002], idx;
bool f[2000002];
vector<ll> son[2000002];
ll calc(ll x) {
	col[x] = idx;
	return max(0ll, r[x - 1] - max(x + 1, (x > 2 ? r[x - 2] : 0) + 1) + 1);
}
void init(ll x) {
	for (ll y : son[x]) dep[y] = dep[x] + 1, init(y);
}
void dfs(ll x, ll b1, ll b2, ll s) {
//	cout << x << ":" << b1 << " " << b2 << " " << s << " " << calc(x) << "\n";
	ans += s;
	if (f[b1]) ans += max(0ll, b2 - r[b1]);
	if (f[x]) b2 = b1, b1 = x, s = 0;
	s += calc(x);
	if (r[x] == x + 1) ans -= calc(r[x]); 
	if (r[r[x]] != r[x] && r[r[x]] == x + 2) ans -= calc(r[r[x]]); 
//	cout << x << ": ans = " << ans << "\n";
	for (ll y : son[x]) dfs(y, b1, b2, s);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while (T -- ) {
		cin >> n >> d; ans = idx = 0;
		for (ll i = 1; i <= n; i ++ ) cin >> X[i], r[i] = f[i] = dep[i] = col[i] = 0, son[i].clear();
		for (ll i = 1, j = 1; i <= n; i ++ ) {
			while (j <= n && X[j] <= X[i] + d) j ++;
			r[i] = j - 1; if (r[i] != i) son[r[i]].push_back(i);
//			f[i] = (r[i] != i && i > 1 && X[r[i]] <= X[i - 1] + d && (i <= 2 || X[r[i]] > X[i - 2] + d));
		}
		for (ll i = 1; i <= n; i ++ ) if (r[i] == i) idx ++, init(i);
		for (ll i = 2; i <= n; i ++ ) f[i] = (col[i] == col[i - 1] && dep[i] == dep[i - 1] && (i == 2 || col[i] != col[i - 2] || dep[i] != dep[i - 2]));
//		for (ll i = 1; i <= n; i ++ ) cout << i << ": " << f[i] << " " << r[i] << "\n";
		for (ll i = 1; i <= n; i ++ ) if (r[i] == i) dfs(i, i, i, 0);
		cout << ans << "\n";
	}
}
/*
0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

ans = 12

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

ans = 6

0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32

ans = 7


1h.打你吗。 
15min.give up.dabaoli.mademeiyoubaolinengda,sile.

对的有点多，每个大样例好像错一两个。能不能给我几分求你了。 

我好想去WC啊。 
*/
