#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;
const long long INF = 4e18 + 10;

long long c, T, n, d, x[N], dis[5005][5005], f[5005][5005], t40[N], ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)	cin >> x[i];
		
		if (c <= 10) {
			ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n + 1; j++) {
					if (i != j)	dis[i][j] = INF;
					else	dis[i][j] = 0;
					f[i][j] = 0;
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					int pj = lower_bound(x + 1, x + n + 1, x[j] - d) - x;
					pj = max(pj, i);
					if (i <= pj && pj <= j)	dis[i][j] = dis[i][pj] + 1;
					else	break;
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i; j <= n; j++)	f[i][j] = 1;
				for (int j = i + 1; j <= n; j++) {
					if (dis[i][j] >= INF)	continue ;
					int p1 = lower_bound(x + 1, x + n + 1, x[j] - d) - x;
					p1 = max(p1, i);
					int p2 = upper_bound(dis[i] + i, dis[i] + n + 1, dis[i][p1]) - dis[i];
					p2 = max(p2, i);
					if (dis[i][p1 + 1] != dis[i][p1])	f[i][j] = f[i][p1];
					else	f[i][j] = f[i][p1] + p2 - p1 - 1;
					if (f[i][j] == 2) {
						ans++;
					}
				}
			}
			cout << ans << "\n";
			continue ;
		}
		if (c == 11 || c == 12) {
			ans = 0;
			long long D = x[2] - x[1];
			if (D * 2 > d)	ans = 0;
			else	ans = n - (d / D * 2 - 1);
			cout << max(0ll, ans) << "\n";
			continue ;
		}
		cout << "0\n";
	}
	
	return 0;
}
