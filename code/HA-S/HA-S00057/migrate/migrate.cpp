#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[2000005],dp[2000005],sum[2000005],ans;
void solve(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	ans=0;
	for(int i=1;i<=n;i++){
		memset(dp,0x3f,sizeof dp);
		memset(sum,0,sizeof sum);
		dp[i]=0;
		sum[i]=1;
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<j;k++){
				if(abs(x[j]-x[k])<=d){
					if(dp[k]+1==dp[j]){
						sum[j]+=sum[k];
					}else if(dp[k]+1<dp[j]){
						sum[j]=sum[k];
						dp[j]=dp[k]+1;
					}
				}
			}
			if(sum[j]==2)ans++;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)solve();
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
