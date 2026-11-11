#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll c, t, n, d, a[2000005], f, o;
void dfs(ll x, ll e, ll u) {
	if (u == o) {
		if (x == e) {
			f++;
		}
		return;
	}
	int i = x + 1;
	while (a[i] - a[x] <= d && i <= e) {
		dfs(i, e, u + 1);
		i++;
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		ll g = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = i + 2; j <= n; j++) {
				ll l = i, z = 0;
				while (l < j) {
					ll p = l;
					while (a[p] - a[l] <= d && p <= j) {
						p++;
					}
					if (p == l || p - 1 == l) {
						z = 1;
						break;
					}
					l = p - 1;
					//cout << l << " ";
					o++;
				}
				if (z == 1) continue;
				//cout << i << " " << j << "\n";
				//cout << o << "\n";
				dfs(i, j, 0);
				if (f == 2) {
					g++;
					//cout << i << " " << j << "\n";
				}
				o = 0, f = 0;
			}
		}
		cout << g << "\n";
	}
	return 0;
}
