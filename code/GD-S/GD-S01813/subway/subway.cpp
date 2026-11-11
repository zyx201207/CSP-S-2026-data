#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 500050;
int n, m, i, j, k, x, y, u, v, c, a[M];
long long ans, f[N][N];
vector <long long> vec[M];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%*d%d%d%*d%d", &n, &m, &c);
	for(i=1; i<=m; i++) scanf("%d", a+i);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++) f[i][j] = i!=j?1e18:0;
	}
	for(i=1; i<=n; i++){
		scanf("%d", &y);
		for(x=1; x<=y; x++){
			scanf("%d%d", &k, &u);
			for(auto w : vec[k]){
				j = w%N, v = w/N;
				f[i][j] = f[j][i] = min(f[i][j], 0ll+u+v);
			}
			vec[k].push_back(1ll*u*N+i);
		}
	}
	for(k=1; k<=n; k++){
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				if(i != j) f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
			}
		}
	}
	while(c--){
		scanf("%d%d", &x, &y);
		ans = 1e18;
		for(auto w : vec[x]){
			i = w%N, u = w/N;
			for(auto ww : vec[y]){
				j = ww%N, v = ww/N;
				ans = min(ans, a[x]+u+f[i][j]+v+a[y]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
