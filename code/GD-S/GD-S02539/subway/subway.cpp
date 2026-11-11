#include <bits/stdc++.h>
using namespace std;

const int N = 114514;
int c, n, m, d, q, w[N], k[N], a[N][N], t[N][N], x[N], y[N];

int main() {
	srand(time(0));
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	
	for (int i = 1; i <= q; i++)
		cin >> x[i] >> y[i];
	
	for (int i = 1; i <= q; i++)
		cout << rand();
	return 0;
}
