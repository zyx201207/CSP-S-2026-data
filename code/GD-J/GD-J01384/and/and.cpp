#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int dp[2005][2005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)dp[i][1]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			for(int k=0;k<m;k++){
				dp[i][k+1]=max(dp[i][k+1],dp[j][k]&a[i]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
} 
