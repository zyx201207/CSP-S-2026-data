#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5;
int c, t;
int n, d;
int x[N];
int ans[N][N];
void dfs(int u, int dis) {
	for (int i = u + 1; i <= n; i++) {
		if (x[i] - x[u] < d) {
			
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			ci >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			int to = 0;
			for (int j = i; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					to = max(to, j);
				} else {
					break;
				}
			}
			
		}
	}
	return 0;
}

