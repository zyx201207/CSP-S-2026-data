#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	dp[0]=1;
	if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;++i) ans=a[i]&ans;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=m;++i){
		dp[i]=dp[i-1]&a[1];
		for(int j=2;j<=n;++j){
			dp[i]=max(dp[i],dp[i-1]&a[j]);
		}
	}
	cout<<dp[m];
	return 0;
} 
