#include <bits/stdc++.h>
using namespace std;
                                            //500010
long long c, n, m, d, q, w[500010], k, z[510][500010][2], x[100010], y[10010];

void bfs(int x_, int y_) {
	
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++) cin >> w[i];
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) cin >> z[i][j][0] >> z[i][j][1];
	}
	for (int i = 0; i < q; i++) cin >> x[i] >> y[i];
	
	return 0;
}

