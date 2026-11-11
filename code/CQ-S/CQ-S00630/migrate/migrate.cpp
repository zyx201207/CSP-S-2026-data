#include<bits/stdc++.h>
using namespace std;
long long Test,T;
long long n,m;
long long num[550];
long long Min[550][550];
long long dp[550][550];
long long ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>Test;
	cin>>T;
	while (T--){
		cin>>n>>m;
		ans = 0;
		for (long long i = 1;i <= n;i++){
			cin>>num[i];
		}
		for (long long i = 1;i <= n;i++){
			for (long long j = 1;j <= n;j++){
				Min[i][j] = 1e18;
			}
			Min[i][i] = 0;
		}
		for (long long j = 1;j <= n;j++){
			for (long long i = j-1;i >= 1;i--){
				if (num[j]-num[i] <= m){
					Min[i][j] = 1;
				}
				for (long long k = i;k <= j;k++){
					Min[i][j] = min(Min[i][j],Min[i][k]+Min[k][j]);
				}
			}
		}
		for (long long i = 1;i <= n;i++){
			for (long long j = i+1;j <= n;j++){
				dp[i][j] = 0;
			}
		}
		for (long long j = 1;j <= n;j++){
			for (long long i = j-1;i >= 1;i--){
				if (num[j]-num[i] <= m){
					dp[i][j] = 1;
				}
				for (long long k = i+1;k <= j-1;k++){
					if (Min[i][j] == Min[i][k]+Min[k][j] && Min[i][k] == 1){
						dp[i][j] += dp[i][k]*dp[k][j];
					}
				}
				if (dp[i][j] == 2){
					ans++;
				}
			}
		}
//		for (long long i = 1;i <= n;i++){
//			for (long long j = i;j <= n;j++){
//				cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
//			}
//		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/
