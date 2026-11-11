#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 3;
int c, T, n, d;
int a[MAXN];
bool check() {
	int d = a[2] - a[1];
	for(int i = 2; i <= n; i++) if(a[i] != (a[i - 1] + d)) return false;
	return true;
}
void solve() {
	cin >> n >> d;
	if(n == 2 || n == 1) {
		cout << 0 << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (check()) {
		int dis = a[2] - a[1];
		if(d / dis != 2) {
			cout << 0 << '\n';
			return;
		} else {
			int p = d / dis + 1;
			int ans = 0;
			for (int i = 1; i <= n; i++) if(i + p <= n) ans++;
			cout << ans << '\n';
			return;
		}
	}
	
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c >> T;
	while(T--) solve();
	return 0;
}
