// GZ-S00256 ≥¬Í≈÷Ò 
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5+10;
int c, n, m, DD, q;
int w[N], k[N];
int x, y;
int d[510][510];
vector<int> a[550], t[550];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> DD >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	if(c >= 7 && c <= 11) {
		memset(d, 0x3f, sizeof(d));
		for(int i = 1; i <= n; i++) {
			if(k[i] != 2) continue;
			int u = a[i][0], v = a[i][1], W = t[i][0] + t[i][1];
			d[u][v] = d[v][u] = min(d[u][v], W);
		}
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= m; j++) {
				for(int k = 1; k <= m; k++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		while(q--) {
			cin >> x >> y;
			cout << w[x] + w[y] + d[x][y] << "\n";
		}
	} else if(c >= 12 && c <= 19) {
		memset(d, 0x3f, sizeof(d));
		int len = t[1][1]*2;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < k[i]; j++) {
				for(int l = 0; l < k[i]; l++) {
					if(l == j) continue;
					int u = a[i][j], v = a[i][l];
					d[u][v] = d[v][u] = len;
				}
			}
		}
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= m; j++) {
				for(int k = 1; k <= m; k++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		while(q--) {
			cin >> x >> y;
			cout << w[x] + w[y] + d[x][y] << "\n";
		}
	}
	return 0;
}
