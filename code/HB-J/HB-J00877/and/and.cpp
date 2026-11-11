#include<bits/stdc++.h>
using namespace std;
const int Q=2e5+5;
int dp[Q],a[Q];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int maxing=a[1]; dp[1]=a[1];
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]&a[i];
		maxing=max(maxing,a[i]); dp[1]=maxing;
		for(int j=i-1;j>=2;j--)
			dp[j]=max(dp[j],dp[j-1]&a[i]);
	}
	cout<<dp[m];
	return 0;
}
