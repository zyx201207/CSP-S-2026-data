#include<bits/stdc++.h>
using namespace std;

int w[500010], k[510], a[510][1010], t[510][1010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++) {
		cin >> w[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> k[i];
		for(int j=1; j<=k[i]; i++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + t[x][1] + t[y][1] + w[y] << "\n";
	}
	return 0;
}
