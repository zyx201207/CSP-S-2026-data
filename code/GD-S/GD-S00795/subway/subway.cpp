#include <bits/stdc++.h>
using namespace std;
#define int long long

int w[500010];
int a[510][50010];
int t[510][50010];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		ans += w[x] + w[y];
		int l = -1;
		for(int j = 1; j <= n; j++) {
			if(a[j][x] != 0) {
				l = j;
				break;
			}
		}
		ans += a[l][x];
		if(a[l][y] != 0) ans += a[l][y];
		else {
			int o = 1; 
			for(int j = 2; j <= n; j++) {
				if(a[j][y] == 0) o++;
				else break;
			}
			ans += o * a[l][y];
		}
		cout << ans << '\n';
	}

	return 0;
}
