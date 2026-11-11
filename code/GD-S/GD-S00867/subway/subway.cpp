#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, x, s, a, b, k[500005], t[505][500005];
vector<int> vec[500005];
void dij(int st) {
	
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> k[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> x;
		int p = 0;
		for (int j = 1; j <= x; j++) {
			cin >> s >> t[i][s];
			if (p != 0) {
				vec[p].push_back(s);
				vec[s].push_back(p);
			}
			p = s;
		}
	}
	while (q--) {
		cin >> a >> b;
		dij(a);
		cout << dis[b];
	}
	return 0;
}
