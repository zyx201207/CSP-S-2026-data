//migrate
#include <bits/stdc++.h>
#define int long long
using namespace std;

int c,t,n,d,ans,x[2000005],dp[305][305][305];//dp[i][j][k]:从i到j长度为k的路径数量 

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t --){
		ans = 0;
		scanf("%lld%lld",&n,&d);
		bool b = 0;
		int maxx = -1e18 - 1;
		for (int i = 1;i <= n;i ++){
			scanf("%lld",&x[i]);
			if (x[i] < 1){
				b = 1;
				maxx = max(maxx,1 - x[i]);
			}
		}
		if (b){
			for (int i = 1;i <= n;i ++){
				x[i] += maxx;
			}
		}
		for (int i = 1;i <= n;i ++){
			for (int j = 1;j <= n;j ++){
				for (int k = 1;k <= n;k ++){
					dp[i][j][k] = 0;
				}
			}
		}
		for (int i = 1;i <= n;i ++){
			dp[x[i]][x[i]][0] = 1;
		}
		for (int i = 1;i <= n;i ++){
			for (int j = i;j <= n;j ++){
				for (int k = 1;k < n;k ++){
					for (int l = 1;l <= min(n,d);l ++){
						dp[x[i]][x[j]][k] += dp[x[i]][x[j] - l][k - 1]; 
					}
				}
			}
		}
		for (int i = 1;i <= n;i ++){
			for (int j = i + 1;j <= n;j ++){
				for (int k = 1;k < n;k ++){
					if (dp[x[i]][x[j]][k] > 0){
						if (dp[x[i]][x[j]][k] == 2){
							ans ++;
						}
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/* 
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
