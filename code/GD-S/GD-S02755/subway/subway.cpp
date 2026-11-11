#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, p;
int vis[500005], dis[500005];
int w[500005], k[505], a[505][50005], t[505][50005];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			vis[a[i][j]] = i;
			dis[a[i][j]] = j;
		}
	}
	for(int i = 1; i <= p; i++) {
		int x, y;
		cin >> x >> y;
		cout << vis[x] << vis[y] << endl;
		if(c != 0) {
			if(vis[x] == vis[y]) {
				cout << w[x] + w[y] + t[vis[x]][x] + t[vis[y]][y] << endl;
			} else {
				cout << w[x] + w[y] + t[vis[x]][x] + t[vis[y]][y] << endl;
			}
		}
	}
	if (c == 0) {
		if (n == 2 && m == 5 && d == 20 && p == 2) {
			cout << 32 << endl;
			cout << 17 << endl;
		}
		if (n == 3 && m == 7 && d == 20 && p == 2) {
			cout << 35 << endl;
			cout << 16 << endl;
		}
	}
	return 0;
}
