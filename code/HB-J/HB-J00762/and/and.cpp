#include<bits/stdc++.h>
using namespace std;
const int man=1e4+10;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100010],dp[man][man]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][1]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j-1]&a[i]));
		}
	}
	cout<<dp[n][m];
	return 0;
}
