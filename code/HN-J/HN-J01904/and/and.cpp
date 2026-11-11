#include<bits/stdc++.h>
using namespace std;
long long dp[200005][200005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(n-i<=j){
				dp[i][j]=dp[i][j-1]^a[i];
			}else{
				dp[i][j]=max(dp[i][j],dp[i][j-1]^a[i]);
			}
		} 
	}
	cout<<dp[n][m];
	return 0;
}
/*
不知道咋改了
4tps++ 
*/
