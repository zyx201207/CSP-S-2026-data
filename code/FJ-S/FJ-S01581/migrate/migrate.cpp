#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t;
int x[2001000];
int dis[10000][10000];
int cnt[10000][10000];
int n, d;
bool vis[10010][10000];
int32_t main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		memset(x, 0, sizeof x);
		memset(dis, 0, sizeof dis);
		memset(cnt, 0, sizeof cnt);
		
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) {
					dis[i][j] = 0;
					cnt[i][j] = 1;
					continue;
				}
				if (d >= abs(x[i]-x[j])){
					dis[i][j] = abs(x[i]-x[j]); 
					cnt[i][j] = 1;
				} else {
					dis[i][j] = 1e18; 
				}
			} 
		}
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (dis[i][k] != 1e18 && dis[k][j] != 1e18 && i != j) {
						if (dis[i][j] > dis[i][k] + dis[k][j]) {
							dis[i][j] = dis[i][k] + dis[k][j];
							cnt[i][j] = cnt[i][k] * cnt[k][j];
						} else if (dis[i][j] == dis[i][k] + dis[k][j] && i != j) {
							cnt[i][j] += cnt[i][k] * cnt[k][j];
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= n; ++j) {
				if(cnt[i][j] == 2 && !vis[i][j] && j != i) {
					ans++;
					vis[i][j] = 1;
				}
			}
		}
		cout << ans << '\n';
		
	}
	return 0;
}
