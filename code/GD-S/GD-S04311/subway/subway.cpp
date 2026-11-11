#include <bits/stdc++.h>
#define M 20050
#define N 505 
#define ll long long
using namespace std;
ll m, n, i, j, k[N], c, d, q, ii, jj, w[M], x, y, f[M], h[M], e[M][30], g[M][30], a[N][M], t[N][M];
//void bianli(ll x, ll eg){
//	int i, j, b;
//	for(i=1; i<=k[eg]; i++){
//		b = a[eg][i];
//		if(b == x) continue;
//		
//	}
//}
queue<ll> st, v;
ll BFS(ll x, ll y){
	ll i, j, cnt=0, b, eg, r, l, cd;
	memset(f, 0x3f, sizeof(f));
	while(st.size()) st.pop();
	while(v.size()) v.pop();
	f[x] = 0, st.push(x), v.push(0);
	while(st.size()){
		b = st.front(), r = v.front(), st.pop(), v.pop();
		for(i=1; i<=h[b]; i++){
			eg = e[b][i];
			if(eg == r) continue;
			for(j=1; j<=k[eg]; j++){
				l = a[eg][j], cd = f[b]+t[eg][g[b][eg]]+t[eg][j];
				if(l == b) continue;
				if(cd >= f[l]) continue;
				f[l] = cd, st.push(l), v.push(eg);
//				printf("%d %d %d %d %d\n", b, l, f[b], f[l], t[eg][g[b][eg]]+t[eg][j]);
			}
		}
	}
//	for(i=1; i<=n; i++) g[i] = 0;
//	for(i=1; i<=h[x]; i++){
//		eg = e[x][1];
//		for(j=1; j<=k[])
//	}
//	while(cnt <= n){ 
////		bianli(g[x[cnt]], x[cnt]);
//	}
//	for(i=1; i<=m; i++) printf("%d ", f[i]);
	return w[x]+w[y]+f[y];
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(i=1; i<=m; i++) scanf("%lld", &w[i]);
	for(i=1; i<=n; i++){
		scanf("%lld", &k[i]);
		for(j=1; j<=k[i]; j++){
			scanf("%lld%lld", &a[i][j], &t[i][j]);
			e[a[i][j]][++h[a[i][j]]] = i, g[a[i][j]][i] = j;
		}
	}
//	for(i=1; i<=m; i++){
//		printf("\n%d \n", i);
//		for(j=1; j<=h[i]; j++){
//			for(ii=1; ii<=k[e[i][j]]; ii++){
//				printf("%d ", a[e[i][j]][ii]);
//			}
//		}
//	}
	while(q--){
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", BFS(x, y));
	}
	return 0;
}

