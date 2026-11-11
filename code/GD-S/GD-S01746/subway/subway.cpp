#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
int cid , n , m , d , q;
int w[N] , maxd;
int f[N][N];
int l[N] , t[N][N] , a[N][N];
vector <int> p[505];

signed main () {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> cid >> m >> n >> d >> q;
	for (int i = 1 ; i <= n ; i++)
		cin >> w[i];
	for (int i = 1 ; i <= m ; i++) {
		cin >> l[i];
		maxd = max (maxd , l[i]);
		for (int j = 1 ; j <= l[i] ; j++)
			cin >> a[i][j] >> t[i][j];
	}
	if (maxd * maxd * m <= 5e7) {
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= n ; j++)
				f[i][j] = 1e18;
		for (int i = 1 ; i <= m ; i++) {
			for (int j = 1 ; j <= l[i] ; j++)
				for (int k = 1 ; k <= l[i] ; k++)
					f[a[i][j]][a[i][k]] = min (f[a[i][j]][a[i][k]] , t[i][j] + t[i][k]);
		}
		for (int k = 1 ; k <= n ; k++)
			for (int i = 1 ; i <= n ; i++)
				for (int j = 1 ; j <= n ; j++)
					f[i][j] = min (f[i][j] , f[i][k] + f[k][j]);
		while (q--) {
			int x , y;
			cin >> x >> y;
			cout << w[x] + w[y] + f[x][y] << endl;
		}
		return 0;
	}
	for (int i = 1 ; i <= m ; i++)
		for (int j = 1 ; j <= l[i] ; j++)
			p[a[i][j]].push_back (i);
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= n ; j++)
			f[i][j] = 1e18;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = i+1 ; j <= n ; j++) {
			bool flag = false;
			for (int k : p[i]) {
				for (int l : p[j]) {
					if (k == l)
						flag = true;
				}
			}
			if (flag) f[i][j] = 1;
		}
	}
	for (int k = 1 ; k <= n ; k++)
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= n ; j++)
				f[i][j] = min (f[i][j] , f[i][k] + f[k][j]);
	while (q--) {
		int x , y;
		cin >> x >> y;
		cout << w[x] + w[y] + (f[x][y]) * 2 * t[1][1] << endl;
	}
	return 0;
}
