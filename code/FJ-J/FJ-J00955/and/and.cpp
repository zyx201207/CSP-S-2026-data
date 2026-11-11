#include<bits/stdc++.h>
using namespace std;
long long a[250000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long dp[n+1][m+1];
	dp[0][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,m);j++){
			if(j==1){
				dp[i][j]=max(dp[i-1][j],a[i]);
				continue;
			}
			if(i==j){
				dp[i][j]=(dp[i][j-1]&a[i]);
			}else{
				dp[i][j]=max((dp[i-1][j-1]&a[i]),dp[i-1][j]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}
