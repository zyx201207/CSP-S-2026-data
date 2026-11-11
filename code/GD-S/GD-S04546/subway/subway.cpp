#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int k, a, t;
int from, to;
int _len;
int _a, _b; long long _c;
int stnex[1003];
int A[5000003], B[5000003]; long long C[5000003];
long long cost[1503];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d", &stnex[i]);
	
	for(int i=1;i<=n;i++){
		scanf("%d", &k);
		for(int j=1;j<=k;j++){
			scanf("%d", &a);
			scanf("%d", &t);
			A[++_len] = i+1000;
			B[_len] = a;
			C[_len] = t;
			A[++_len] = a;
			B[_len] = i+1000;
			C[_len] = t;
		}
	}
	
	
	for(int I=1;I<=q;I++){
		for(int i=1;i<=m;i++) cost[i] = 1e15;
		for(int i=1001;i<=1000+n;i++) cost[i] = 1e15;
		scanf("%d%d", &from, &to);
		cost[from] = 0;
		for(int i=1;i<=_len;i++){
			int canstop = 1;
			for(int j=1;j<=_len;j++){
				_a = A[j], _b = B[j], _c = C[j];
				if(cost[_b]-_c > cost[_a]){
					cost[_b] = cost[_a]+_c;
					canstop = 0;
				}
			}
			if(canstop) break;
		}
		printf("%lld\n", cost[to]+stnex[from]+stnex[to]);
	}
	
//	for(int j=1;j<=_len;j++) printf("[%d %d %lld]\n", A[j], B[j], C[j]);
	
	return 0;
}
