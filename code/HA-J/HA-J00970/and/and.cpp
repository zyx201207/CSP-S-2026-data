#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long dp[10005][10005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[i][1]=a[i];
	}
	for(int i=2;i<=m;i++){
		//dp[1][i]=dp[1][i-1];
		for(int j=2;j<=n;j++){
			dp[j][i]=max(dp[j-1][i-1]&a[j],dp[j-1][i]);
			//cout<<dp[j][i]<<' ';
		}
		//cout<<endl;
	}
	cout<<dp[n][m];
	return 0;
}
