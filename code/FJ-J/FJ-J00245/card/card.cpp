#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000005];
long long dp[1000001][1000001];
long long f;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[1][1]=a[1];

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i-j<=0){
				dp[i][j]=dp[i][j-1];
			}
			dp[i][j]=max(dp[i][j-1],dp[i][j-1]&a[j]);
		}
	}
	cout<<dp[m][n];
}
