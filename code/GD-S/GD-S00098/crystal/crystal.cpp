#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		long long we[50005];
		long long dp[m+5];
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=n;++j){
			we[j]=a[i]-a[j];
		}
		for(int j=1;j<=n;++j){
			if(we[j]<0) break;
			for(int k=m;k>=we[j];--k){
				dp[k]=max(dp[k],dp[k-we[j]]+1);
			}
		}
		ans=max(ans,dp[m]);
	}
	cout<<ans;
	return 0;
} 
