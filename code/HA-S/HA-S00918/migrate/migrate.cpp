#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e6 + 10, M = 5e3 + 10;

int c, T, n;
ll d, a[N];
ll dp[M][M], G[M][M];
int f[N];
ll ans;

void work(){
	scanf("%d%lld", &n, &d);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
	}
	
	if(n <= 3){
		printf("0\n");
		return ;
	}
	if(c <= 10){	
		int r = n;
		for(int i = n;i >= 1;i--){//找到i向右一次性能跳到的最远下标 
			while(r - 1 >= i && a[r] - a[i] > d)	r--;
			f[i] = r;
		}
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				dp[i][j] = 1e18;
				G[i][j] = 0;
			}
			dp[i][i] = 0;
		}
		for(int len = 1;len <= n;len++){
			for(int i = 1;i + len - 1 <= n;i++){
				int j = i + len - 1;
				if(f[i] >= j){
					dp[i][j] = 1;
					G[i][j] = 1;
					continue;
				}
				for(int k = i + 1;k < j;k++){
					if(dp[i][j] > dp[i][k] + dp[k][j]){
						dp[i][j] = dp[i][k] + dp[k][j];
						G[i][j] = G[i][k] * G[k][j];
					}else if(dp[i][j] == dp[i][k] + dp[k][j]){
						G[i][j] += G[i][k] * G[k][j];
					}
				}
			}
		}
		ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(G[i][j] == 2){
					ans++;
//					printf("(%d, %d) - %lld\n", i, j, dp[i][j]);	
				}
			}
		}
		printf("%lld\n", ans);
	}else{
		ll D = a[2] - a[1];
		ll len = d / D;
		printf("%lld\n", n - len + 1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d", &c, &T);
	while(T--){
		work();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
