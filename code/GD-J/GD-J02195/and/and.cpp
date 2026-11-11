#include<bits/stdc++.h>
using namespace std;
int dp[200005][200005],a[200005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]);
		dp[i][1]=maxn;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(j>i)continue;
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
}
