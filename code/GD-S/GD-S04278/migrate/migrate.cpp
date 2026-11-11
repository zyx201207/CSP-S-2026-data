#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 2e6 + 10, INF = 1e9;

int c, t;

int n, d;
int x[maxn];

int ans, minr, cnt;

void dfs(int now, int total, int dep) {
	if (now == total) {
		if (minr > dep) minr = dep, cnt = 0;
		if (minr == dep) ++cnt;
		return ;
	}
	
	for (int i = now + 1; i <= total; i++) {
		if (abs(x[i] - x[now]) <= d) {
			dfs(i, total, dep + 1);
		}
	}
}

void sol() {
	cin >> n >> d;
	
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	
	if (n > 5000) {
		bool flag = true;
		int te = x[2] - x[1];
		for (int i = 2; i <= n; i++) {
			if (x[i] - x[i - 1] != te) {
				flag = false;
				break;
			}
		}
		
		if (flag) {
			if (d < 2 * x[1] || d >= 3 * x[1] || n <= 3) {
				cout << 0 << '\n';
				return ;
			}
			
			int res = n - 3;
			cout << res << '\n';
		} else {
			cout << 0 << '\n';
		}
		return ;
	}
	
	ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l + 1; r <= n; r++) {
			minr = INF, cnt = 0;
			dfs(l, r, 0);
			if (cnt == 2) ans++;
		}
	}
	
	cout << ans << '\n';
}

signed main() {
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while(t--) sol();
	
	return 0;
}
