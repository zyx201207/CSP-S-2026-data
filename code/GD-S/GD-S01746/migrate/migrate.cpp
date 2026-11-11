#include <bits/stdc++.h>
using namespace std;
#define int long long

int n , d;
int f[305][305][2] , g[305][305] , a[305];

void solve () {
	scanf("%lld%lld" ,&n , &d);
	for (int i = 1 ; i <= n ; i++)
		scanf("%lld" ,&a[i]);
	int D = 0;
	bool CaseA = true;
	D = a[2] - a[1];
	for (int i = 2 ; i <= n ; i++) 
		CaseA &= (D == a[i]-a[i-1]);
	if (n <= 300) {
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= n ; j++)
				f[i][j][0] = f[i][j][1] = g[i][j] = 1e18;
		for (int i = 1 ; i <= n ; i++)
			for (int j = i+1 ; j <= n ; j++)
				if (a[j] - a[i] <= d)
					f[i][j][0] = f[i][j][1] = 1;
		int cnt = 0;
		for (int k = 1 ; k <= n ; k++)
			for (int i = 1 ; i <= n ; i++)
				for (int j = 1 ; j <= n ; j++) {
					if (f[i][k][0] + f[k][j][0] < f[i][j][0]) {
						f[i][j][0] = f[i][k][0] + f[k][j][0];
						f[i][j][1] = f[i][k][1] * f[k][j][1];
					} else if (f[i][k][0] + f[k][j][0] == f[i][j][0]) {
						f[i][j][1] += f[i][k][1] * f[k][j][1];
					}
				}
		for (int i = 1 ; i <= n ; i++)
			for (int j = i+1 ; j <= n ; j++)
				if (f[i][j][1] == 2)
					cnt++;
		printf("%lld\n" , cnt);
		return;
	}
}

signed main () {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int cd;
	int T;
	scanf("%lld%lld" ,&cd ,&T);
	while (T--)
		solve();
	return 0;
}
