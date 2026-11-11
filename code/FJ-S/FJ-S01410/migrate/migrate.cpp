#include<bits/stdc++.h>
using namespace std;
const int MAXN = 310;
long long c,t,n,d,ans,a[MAXN],pos[MAXN],dp[MAXN][MAXN],sum[MAXN][MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> d;
		for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i = 1;i<=n;i++){
			int flag = 1;
			for(int j = i-1;j>=1;j--){
				if(a[i]-a[j]>d){
					pos[i] = j,flag = 0;
					break;
				}
			}
			if(flag) pos[i] = 0;
		}
		for(int i = 1;i<=n;i++){
			for(int j = 0;j<=n;j++)
				for(int k = 0;k<n;k++)
					dp[j][k] = sum[j][k] = 0;
			for(int j = 1;j<=n;j++) dp[i][j] = sum[i][j] = 0;
			dp[i][0] = sum[i][0] = 1;
			for(int j = i+1;j<=n;j++){
				for(int k = 0;k<=(j-i);k++){
					dp[j][k] = sum[j-1][k-1]-sum[pos[j]][k-1];
					sum[j][k] = sum[j-1][k]+dp[j][k];
				}
			}
			for(int j = i+1;j<=n;j++){
				for(int k = 1;k<=(j-i+1);k++){
					if(dp[j][k]>0){
						ans += (dp[j][k]==2);
						break;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
