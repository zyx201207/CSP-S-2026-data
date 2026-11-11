#include <bits/stdc++.h>
#define endl '\n'
#define fn "subway"
typedef long long ll;
using namespace std;
ll c, n, m, d, q, w[500050], k[550], a[550][500050], t[550][500050], x[100010], y[100010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen(fn ".in", "r", stdin);
	freopen(fn ".out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i ++){
		cin >> x[i] >> y[i];
	}
	for (int r = 1; r <= q; r ++){
		int ans = w[x[r]] + w[y[r]];
		cout << ans;
	}
	return 0;
}
