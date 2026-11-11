#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],dp[2005][2005],maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)dp[i][1]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(j>2)
			dp[i][j]=max(dp[i][j-1]&a[i],dp[i-1][j-1]&a[i]);
			else dp[i][j]=dp[i-1][j-1]&a[i];
		}
		maxn=max(maxn,dp[i][m]);
	}
	cout<<maxn;
	
    return 0;
}
