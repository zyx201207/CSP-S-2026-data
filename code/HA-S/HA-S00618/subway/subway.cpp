#include <bits/stdc++.h>
using namespace std;

const int N = 505;
long long c, n, m, dd, q, k, w[N], a[N], t[N], x, y;
long long d[N][N];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(d, 0x3f, sizeof(d));
	cin >> c >> n >> m >> dd >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> k;
		for (int j = 1; j <= k; j++)
			cin >> a[j] >> t[j];
		for (int j = 1; j < k; j++)
			for (int kk = j + 1; kk <= k; kk++)
				d[a[j]][a[kk]] = min(t[j] + t[kk], d[a[j]][a[kk]]);
	}
	for (int k = 1; k <= m; k++)
		for (int i = 1; i <= m; i++)
		    for (int j = 1; j <= m; j++)
		        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for (int i = 1; i <= q; i++){
		cin >> x >> y;
		cout << min(d[x][y], d[y][x]) + w[x] + w[y] << '\n';
	}
	return 0;
}
