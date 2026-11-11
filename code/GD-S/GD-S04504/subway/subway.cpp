#include<bits/stdc++.h>
using namespace std;


int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q,w[1005], k, a[3][1005], t[3][1005], x[1005], y[1005], ans = 0;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1; i <= q; i++)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= q; i++) {
		ans = w[x[i]] + w[y[i]];
		for(int j = x[i]; j <= y[i]-1; j++) {
			ans = ans + t[1][j] + t[2][j];
		}
		cout << ans << endl;
	}
	return 0;
}
