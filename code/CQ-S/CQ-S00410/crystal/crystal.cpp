#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],dp[500005],ans;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n); 
	for(int i=1;i<=n;i++) dp[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		dp[i]=min(a[i],m-dp[i+1]);
	}
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}

