#include<bits/stdc++.h>
using namespace std;
const int N=20050;
int k[200050],dp[N][N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		dp[i][1]=max(dp[i-1][1],k[i]);
		dp[i][i]=(i==1?k[i]:(dp[i-1][i-1]&k[i]));
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=min(m,i-1);j++){
			dp[i][j]=max({dp[i-1][j],dp[i-1][j-1]&k[i]});
		}
	}
	cout<<dp[n][m];
	return 0;
}
