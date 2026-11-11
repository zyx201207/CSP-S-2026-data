#include <bits/stdc++.h>
using namespace std;
const int N = 501 + 10;
long long c, n, m, d, q, ans = 1e18, vis[N], t[N][N], k[N], a[N][N], w[N], x[N], y[N], sum;
void dfs(int x, int y, int W, int d, bool ci) {
	if (x == y) {
		int ti = 1;
		for (int i = 1;i <= k[d];i ++) {
			if (a[d][i] == y) ti = i; 
		}
		ans = min(ans, W + t[d][ti]);
		return ;
	}
	
	for (int i = 1;i <= n;i ++) {
		for (int j = 1;j <= k[i];j ++) {
			if (a[i][j] == x) {
//				if (!ci) {
//					W += t[i][j];
//				}
				if (i != d) {
					vis[a[i][j + 1]] = 1;
					dfs(a[i][j + 1], y, W + t[d][j] + t[i][j], i, 1);
					vis[a[i][j + 1]] = 0;
				} else {
					if (vis[a[i][j + 1]]) continue;
					vis[a[i][j + 1]] = 1;
					dfs(a[i][j + 1], y, W, d, 1);
					vis[a[i][j + 1]] = 0;
				}
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i ++) cin >> w[i];
	for (int i = 1;i <= n;i ++) {
		cin >> k[i];
		for (int j = 1;j <= k[i];j ++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1;i <= q;i ++){
		cin >> x[i] >> y[i];
		sum += w[x[i]] + w[y[i]];
		vis[x[i]] = 1;
		dfs(x[i], y[i], 0, 0, 0);
//		cout << ans << " ";
		cout << sum + ans << "\n";
		sum = 0, ans = 1e18;
	}
	
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
