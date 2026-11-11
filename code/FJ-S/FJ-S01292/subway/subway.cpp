#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, k, x, y;
struct N{
	int kz, zz[505];
}a[500005];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> a[i].kz;
	}
	for (int i = 1; i <= n; i++){
		cin >> k;
		for (int j = 1; j <= k; j++){
			int num, t;
			cin >> num >> t;
			a[num].zz[i] = t;
		}
	}
	for (int i = 1; i <= q; i++){
		cin >> x >> y;
	}
	return 0;
}
