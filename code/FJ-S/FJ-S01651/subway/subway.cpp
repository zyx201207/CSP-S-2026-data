#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll c, n, m, d, q, w[500005], r, rr, ans = 9223372036854775807;
struct S{
	ll id, t, sum; 
} k[505][50005];
void dfs(ll x, ll tm) {
	if (x == rr) {
		ans = min(ans, tm);
	}
	for (int i = 1; i <= n; i++) {
		int f = 0, e;
		for (int j = 1; j <= k[i][0].sum; j++) {
			if (k[i][j].id == x) {
				f = 1;
				e = k[i][j].t;
				break;
			}
		}
		if (f) {
			for (int j = 1; j <= k[i][0].sum; j++) {
				if (k[i][j].id == x) {
					continue;
				}
				dfs(k[i][j].id, tm + e + k[i][j].t);
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i][0].sum;
		for (int j = 1; j <= k[i][0].sum; j++) {
			cin >> k[i][j].id >> k[i][j].t;
		}
	}
	while (q--) {
		cin >> r >> rr;
		dfs(r, 0);
		ans += w[r] + w[rr];
		cout << ans;
		ans = 9223372036854775807;
	}
	return 0;
}
