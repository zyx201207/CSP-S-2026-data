#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
struct node{
	int step, num;
};
int T;
int n,m,now,ans;
int a[N];
node dp[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld",&T);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(int i = 1; i <= n; i++){
			scanf("%lld",&a[i]);
			dp[i].step = 1e18;
			dp[i].num = 0;
		}
		ans = 0;
	
		for(int k = 1; k <= n; k++){
			dp[k].step = 0;
			dp[k].num = 1;
			for(int i = k; i <= n; i++){
				if(dp[i].num == 0) break;
				for(int j = i + 1; j <= n; j++){
					if(a[j] - a[i] > m) break;
					if(dp[j].step > dp[i].step + 1){
						dp[j].step = dp[i].step + 1;
						dp[j].num = dp[i].num;
					} else if(dp[j].step == dp[i].step + 1){
						dp[j].num += dp[i].num;
					}
				}
				if(dp[i].num == 2) ans++;
				dp[i].num = 0;
				dp[i].step = 1e18;
			}
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}

