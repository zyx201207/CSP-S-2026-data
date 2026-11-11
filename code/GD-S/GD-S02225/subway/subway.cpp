#include <bits/stdc++.h>
using namespace std;


int k[500010];
long long w[500010];
long long s[500010];
vector<int> a[500010];
long long f[1010][1010];
long long c, m, n, d, q;
vector<long long> t[500010];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if (m <= 1000) {
		for (int i = 1; i <= m; i++) {
			cin >> w[i];
			f[i][i] = 0;
		}
		memset(f, 0x3f, sizeof(f));
		for (int i = 1; i <= n; i++) {
			cin >> k[i];
			a[i].resize(k[i]);
			t[i].resize(k[i]);
			for (int j = 1; j <= k[i]; j++) {
				cin >> a[i][j] >> t[i][j];
				for (int x = 1; x < j; x++) {
					f[a[i][j]][a[i][x]] = t[i][j] + t[i][x];
					f[a[i][x]][a[i][j]] = t[i][j] + t[i][x];
	//					cout << a[i][j] << "==" << t[i][j] + t[i][x] << "==>" << a[i][x] << endl;
	//					cout << a[i][x] << "==" << t[i][j] + t[i][x] << "==>" << a[i][j] << endl;
				}
			}
		} 
		for (int i = 1; i <= m; i++) {
			for (int k = i + 1; k <= m; k++) {
				for (int j = k + 1; j <= m; j++) {
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				}
			}
		}
		for (int i = 1; i <= q; i++) {
			int u, v;
			cin >> u >> v;
			cout << w[u] + f[u][v] + w[v] << endl;
		}
	} else {
		for (int i = 1; i <= m; i++) {
			cin >> w[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> k[i];
			for (int j = 1; j <= k[i]; j++) {
				cin >> a[i][j] >> t[i][j];
				s[a[i][j]] = i;
			}
		} 
		for (int i = 1; i <= q; i++) {
			int u, v;
			cin >> u >> v;
			cout << w[u] + t[s[u]][u] + t[s[v]][v] + w[v] << endl;
		}
	} 
	return 0;
}
