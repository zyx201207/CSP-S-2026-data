#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6 + 5, inf = 2e18;
int c, t, n, d, a[maxn], dis[maxn], nxt[maxn], cnt[maxn];
//void dfs(int x, bool fl, int st){
//	if (st > dis[x] || dis[x] == inf) return;
//	if ((st > 1 || !fl) && dis[x] == st) cnt[x]++;
//	if (x == n || nxt[x] == x) return; dfs(nxt[x], fl, st + 1); 
//	if (!fl) for (int i = x + 1; i < nxt[x]; i++) dfs(i, 1, st + 1);
//}
void solve(){
	cin >> n >> d; int pos = n, ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], nxt[i] = 0;
//	for (int i = n; i >= 1; i--) {while(pos > i && a[pos] - a[i] > d) pos--; nxt[i] = pos;}
//	for (int i = 1; i < n; i++) {
//		int p = i, st = 0; for (int j = i + 1; j <= n; j++) cnt[j] = 0, dis[j] = inf; dis[i] = 0;
//		while(p <= n && nxt[p] != p){++st; for (int j = p + 1; j <= nxt[p]; j++) dis[j] = st; p = nxt[p];} dfs(i, 0, 0);
//		for (int j = i + 1; j <= n; j++) {if (cnt[j] == 2) ++ans;}
//	}
//	cout << ans << '\n';
	int x = d / (a[2] - a[1]), L = 0, R = 0;
//	cout << n << ' ' << a[2] - a[1] << ' ' << d << ' ' << x << '\n'; 
	if (x <= 1) {cout << "0\n"; return;}
	for (int i = 1; i <= n; i++) if (a[i] - a[1] > d) {L = i + x - 2; break;} 
	if (L) cout << n - L + 1 << '\n'; else cout << "0\n";
}
main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t; while(t--) solve();
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
