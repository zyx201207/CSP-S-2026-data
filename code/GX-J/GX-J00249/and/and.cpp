#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int dp[20005][20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[1][1]=a[1];
	int ans=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=min(i,m);j++){
			if(j!=1){
				dp[i][j]=max(dp[i-1][j-1] & a[i],dp[i-1][j]);
			}
			else dp[i][j]=a[i];
			if(j==m) ans=max(ans,dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}

