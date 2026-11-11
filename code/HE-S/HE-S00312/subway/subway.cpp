#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m);
	vector<vector<int>> a(n, vector<int>(k, -1)), t(n, vector<int>(k, -1));
	vector<int> x(q, 0), y(q, 0);
	for (int i = 0; i < m; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for (int i = 0; i < q; i++)
		cin >> x[i] >> y[i];
	return 0;
}
