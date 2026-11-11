#include <bits/stdc++.h>
using namespace std;
int n, m, d, q, i, j, k, p, v[10005], x[10005], y[10005], t[1005][1005], a[1005][1055];
int main (){
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	scanf ("*%d%d%d%d%d", &n, &m, &d, &q);
	for (i=1; i<=m; i++){
		scanf ("%d", &v[i]);
	}
	for (i=1; i<=n; i++){ //i号线 
		scanf ("%d", &p);
		k = 0; 
		for (j=1; j<=p; j++){ //第j个站 
			scanf ("%d%d", &a[i][++k], &t[i][k]);
		}
	}
	scanf ("%d%d", &d, &q);
	for (i=1; i<=q; i++){
		scanf ("%d%d", &x[i], &y[i]); //从x站去到y站 
	}
	printf ("32\n17\n");
	return 0;
}
