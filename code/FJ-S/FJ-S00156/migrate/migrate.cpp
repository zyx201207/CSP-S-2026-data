#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int c = 0;
int t = 0;
long long n = 0;
long long d = 0;
long long x[N];
long long dis[510][510];
long long vis[510][510];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int ttt = 1; ttt <= t; ttt++) {
		memset(dis, 0, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					dis[i][j] = 1;
					vis[i][j] = 1;
				} else {
					break;
				}
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				if (i < k) {
					for (int j = 1; j <= n; j++) {
						if (k < j) {
							if (dis[i][k] + dis[k][j] < dis[i][j]) {
								dis[i][j] = dis[i][k] + dis[k][j];
								vis[i][j] = vis[i][k] * vis[k][j];
							} else if (dis[i][j] == dis[i][k] + dis[k][j]) {
								vis[i][j] += vis[i][k] * vis[k][j];
							}
						}
					}
				}
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i < j) {
					if (vis[i][j] == 2) {
						ans++;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
*/
