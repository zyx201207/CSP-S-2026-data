#include<bits/stdc++.h>
using namespace std;
#define int long long
#define deb(n) cout << #n << " = " << n << '\n';
int c, t;
int n, d;
int x[2000010];
int dis[5010][5010];
int a[5010][5010];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> c >> t;
	while (t--) {
		int ans = 0;
		memset(dis, 0x3f, sizeof(dis));
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		sort(x + 1, x + 1 + n);
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					a[i][j] = dis[i][j] = 1;
//					cout << i << ' ' << j << '\n';
				} else {
					break;
				}
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (dis[i][j] == 0x3f3f3f3f3f3f3f3f) cout << "0 ";
//				else cout << dis[i][j] << ' ';
//			}
//			cout << '\n';
//		}
		
		for (int s = 1; s <= n; s++) {
			for (int e = s + 1; e <= n; e++) {
				int cnt = 0;
				for (int k = s + 1; k <= e - 1; k++) {
//					cout << "\n-------\n";
//					deb(s);
//					deb(e);
//					deb(k);
//					deb(dis[s][k]);
//					deb(dis[k][e]);
//					deb(dis[s][e]);
//					cout << "\n----------\n";
					if (dis[s][k] + dis[k][e] == dis[s][e]) cnt++;
//					deb(cnt);
				}

//				deb(s);
//				deb(e);
//				deb(cnt);
				if (a[s][e]) cnt++;
				if (cnt == 2) {
//					cout << s << ' ' << e << '\n';
					ans++;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
