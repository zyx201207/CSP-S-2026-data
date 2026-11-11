#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 10, M = 5010;
int c, n, nxt[M][20], pre[M];
ll d, x[N], f[M], s[M];
int get(int l, int r) {
	if (l == r) return 0;
	int ans = 0, now = l;
	for (int i = 15; ~i; i--)
		if (nxt[now][i] < r) now = nxt[now][i], ans += (1 << i);
	return nxt[now][0] >= r ? ans + 1 : -1;  
}
int jump(int st, int cnt) {
	for (int i = 15; ~i; i--)
		if (cnt >= (1 << i)) cnt -= (1 << i), st = nxt[st][i];
	return st;
}
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	if (n == 1) return cout << "0\n", void();
	if (c <= 10) {
		for (int i = 1; i <= n; i++) {
			int p = i ^ 1 ? nxt[i - 1][0] : 1;
			while (p < n && x[p + 1] - x[i] <= d) p++;
			nxt[i][0] = p;
		}
		pre[n + 1] = n;
		for (int i = n; i; i--) {
			int p = pre[i + 1];
			while (p > 1 && x[i] - x[p - 1] <= d) p--;
			pre[i] = p;
		}
//		cout << "pre ";
//		for (int i = 1; i <= n; i++) cout << pre[i] << " ";
//		cout << "\n";
		for (int i = 1; i <= 15; i++)
			for (int j = 1; j <= n; j++) nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
		int ans = 0;
		for (int l = 1; l <= n; l++) {
			for (int r = 1; r <= n; r++) f[r] = s[r] = 0;
			f[l] = s[l] = 1;
			for (int r = l + 1; r <= n; r++) {
				int d = get(l, r);
//				cout << "DEBUG: " << l << " " << r << " " << d << "\n";
				if (d < 0) break;
				int l1 = pre[r], r1 = r - 1;
				int l2 = l + d - 1, r2 = jump(l, d - 1);
//				cout << l1 << " " << r1 << "\n" << l2 << " " << r2 << "\n"; 
				int L = max(l1, l2), R = min(r1, r2);
				if (L > R) break;
//				cout << L << " " << R << "\n";
				f[r] = s[R] - s[L - 1];
				if (f[r] >= 3) f[r] = 3;
				if (f[r] == 2) ans++;//cout << "answer: " << l << " " << r << "\n";
				s[r] = s[r - 1] + f[r];
//				cout << f[r] << "\n";
			}
		}
		cout << ans << "\n";
		return;
	}
	if (c >= 11 && c <= 12) {
		ll mx = d / (x[2] - x[1]);
		mx = min(mx, (ll)(n - 1));
//		cout << mx << "\n";
		if (mx <= 1) return cout << "0\n", void();
		ll t = 2ll * mx;
		cout << max(0ll, (ll)n - t + 1) << "\n";
		return;
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T; cin >> c >> T;
	while (T--) solve();
	return 0;
}
