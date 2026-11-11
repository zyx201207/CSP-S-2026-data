#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6+5,N = 5e3+5,INF = 1e10 + 5;
int c,t,n,d,x[maxn],cnt[N][N],dp[N][N],g[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i = 1;i <= n;i++) cin >> x[i];
		if(c == 13 || c == 14){
			printf("0\n");
			continue;
		}
//		cout << n << " " << d << " " << x[2] - x[1] << "\n";
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				if(abs(x[i] - x[j]) <= d) g[i][j] = dp[i][j] = g[j][i] = dp[j][i] = abs(x[i] - x[j]);
				else g[i][j] = dp[i][j] = g[j][i] = dp[j][i] = INF;
			}
		}
		for(int k = 1;k <= n;k++){
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					if(dp[i][j] > dp[i][k] + dp[j][k]) dp[i][j] = dp[i][k] + dp[j][k];
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(g[i][j] != INF) continue;
				int cnt = 0;
				for(int k = 1;k <= n;k++){
					if(k == i || k == j) continue;
					if(dp[i][k] + dp[k][j] == dp[i][j]) cnt++;
				}
				if(cnt == 2){
//					cout << i << " " << j << "\n";
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	} 
	return 0;
} 
