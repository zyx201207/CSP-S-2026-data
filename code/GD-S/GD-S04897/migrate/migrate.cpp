#include<bits/stdc++.h>
#define int long long 
using namespace std;
int dp[5005][5005];
int dp1[5005][5005];
int can[5005][5005];
int a[5005];
void work(){
	int n,d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=2e18;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)can[i][j]=0;
	for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)if(a[j]-a[i]<=d)can[i][j]=1;
	for(int i=1;i<=n;i++)dp1[i][i]=can[i][i]=1,dp[i][i]=0;
	for(int le=2;le<=n;le++)for(int l=1;l+le-1<=n;l++){
		int r=l+le-1,t=0,mi=9e18;
		if(can[l][r]){
			dp[l][r]=1;
			dp1[l][r]=1;
			continue;
		}
		for(int k=l;k<=r;k++){
			//if(l==1&&r==5)cout<<k<<" "<<dp[l][k]<<" "<<dp[k][r]<<endl;
			if(mi==dp[l][k]+dp[k][r])t+=dp1[l][k]*dp1[k][r];
			if(mi>dp[l][k]+dp[k][r])mi=dp[l][k]+dp[k][r],t=dp1[l][k]*dp1[k][r];
		}
		dp[l][r]=mi;
		dp1[l][r]=t;
		//if(t==2&&mi<=2e9)cout<<l<<" "<<r<<endl; 
		if(mi>2e9)dp1[l][r]=0;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cccc,t;
	cin>>cccc>>t;
	while(t--)work();
} 
