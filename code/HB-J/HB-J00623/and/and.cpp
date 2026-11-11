#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,j,k;
int n,m,ans=-100;
int a[200005];
int dp[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(dp,0,sizeof(dp));
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=m;i++){
		for(j=n;j>=1;j--){
			dp[j]=0;
			if(i==1) dp[j]=a[j];
			else{
				for(k=1;k<j;k++){
					dp[j]=max(dp[j],dp[k]&a[j]);
				}
			}
			//for(k=1;k<j;k++)	
		}
		//for(k=1;k<=n;k++){
		//	if(j==n) cout<<dp[k]<<' ';
		//}
		//printf("\n--------\n");
		//ans=max(ans,dp[n]);
	}
	for(i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
