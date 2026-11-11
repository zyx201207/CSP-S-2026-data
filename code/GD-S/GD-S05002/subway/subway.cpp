#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= 2 * k; j++) {
			int tmp;
			cin >> tmp;
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] << '\n';
	}
	return 0;
}
