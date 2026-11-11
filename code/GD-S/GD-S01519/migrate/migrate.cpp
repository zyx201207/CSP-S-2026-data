#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5,MA=1e18;
int c,t,n,d,x[N],dp[N][2];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dp[j][0]=MA,dp[j][1]=0;
			dp[i][0]=0;
			dp[i][1]=1;
			for(int j=i;j<n;j++)for(int k=j+1;k<=n&&x[k]-x[j]<=d;k++){
				if(dp[k][0]==dp[j][0]+1)dp[k][1]+=dp[j][1];
				else if(dp[k][0]>dp[j][0]+1){
					dp[k][0]=dp[j][0]+1;
					dp[k][1]=dp[j][1];
				}
			}
			for(int j=i+1;j<=n;j++)if(dp[j][1]==2)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
