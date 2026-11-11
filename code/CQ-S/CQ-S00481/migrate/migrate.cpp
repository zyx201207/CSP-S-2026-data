#include <bits/stdc++.h>
using namespace std;

int c, T, n, f[5010][5010], dis[5010][5010], l[5010];
long long d, x[2000010];

int main(){
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	scanf ("%d%d", &c, &T);
	for (; T--; ){
		scanf ("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf ("%lld", &x[i]);
		for (int i = 1; i <= n; i++)
			l[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - (x + 1) + 1;
		int ans = 0;
		for (int i = 1; i <= n; i++){
			dis[i][i] = 0, f[i][i] = 1;
			for (int j = i + 1; j <= n; j++)
				if (l[j] == j){
					dis[i][j] = 1 << 30, f[i][j] = 0;
					break;
				}
				else{
					dis[i][j] = dis[i][l[j]] + 1, f[i][j] = f[i][l[j]];
					if (l[j] + 1 < j && dis[i][l[j] + 1] + 1 == dis[i][j])
						f[i][j] += f[i][l[j] + 1];
					if (l[j] + 2 < j && dis[i][l[j] + 2] + 1 == dis[i][j])
						f[i][j] += f[i][l[j] + 2];
					f[i][j] = min(f[i][j], 3);
					ans += (f[i][j] == 2);
				}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
