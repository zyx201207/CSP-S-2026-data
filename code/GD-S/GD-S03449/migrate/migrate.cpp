#include<bits/stdc++.h>
using namespace std;
long long x[2000010],dp[2000010],cnt[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	long long d,ans;
	scanf("%d%d" ,&c,&t);
	while(t--){
		ans = 0;
		scanf("%d%lld" ,&n,&d);
		for(int i = 1;i <= n;i++){
			scanf("%lld" ,&x[i]);
		}
		for(int i = 1;i < n;i++){
			for(int j = i + 1;j <= n;j++){
				dp[j] = 1919810;
				cnt[j] = 0;
			}
			dp[i] = 0;
			cnt[i] = 1;
			int l = i,r = i;
			while(l <= n){
				if(cnt[l] == 2){
					ans++;
				}
				while(r <= n && x[r] - x[l] <= d){
					if(dp[l] + 1 < dp[r]){
						dp[r] = dp[l] + 1;
						cnt[r] = cnt[l];
					}else if(dp[l] + 1 == dp[r]){
						cnt[r] += cnt[l];
					}
					r++;
				}
				if(r > n || x[r] - x[l] > d){
					r--;
				}
				l++;
			}
		}
		printf("%lld\n" ,ans);
	}
	return 0;
}
