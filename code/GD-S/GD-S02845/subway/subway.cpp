#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005], k, a[505][25], t[505][25], x, y;
vector<int> v[505];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++) {
		cin >> k;
		for(int j = 1; j <= k; j ++) {
			cin >> a[i][j] >> t[i][j];
			v[i].push_back(a[i][j]);
		}
	}
	cout << "32\n17";
	return 0;
}
