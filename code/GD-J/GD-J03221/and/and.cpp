#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long dp[n + 1][m + 1];
	memset(dp,0,sizeof dp);
	for(int i =1;i<=n;i++){
		cin>>a[i];
		dp[i][1] = max(dp[i-1][1],a[i]);
	}
	for(int i = 2;i<=m;i++){
		for(int j = i;j<=n;j++){
			dp[j][i] = max(dp[j-1][i-1]&a[j],dp[j-1][i]);
		}
	}
	cout<<dp[n][m];
}
