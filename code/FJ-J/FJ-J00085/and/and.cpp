#include <bits/stdc++.h>
using namespace std;
long long dp[2005][2005];
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	memset(dp,0,sizeof(dp));
	if(n>2000) dp[n][m]=a[m];
	for(int i=1;i<=n;++i) dp[i][0]=2147483647;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=min(i,m);++j){
		    dp[i][j]=dp[i-1][j-1]&a[i];
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}
	}
	cout<<dp[n][m];
	return 0;
}

