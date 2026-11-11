#include<bits/stdc++.h>
using namespace std;
int dp[20005][20005];
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) dp[1][i]=a[i];
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i][j-i+1]&a[j],dp[i-i+1][j-1]&a[j]);
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	cout<<dp[m][n];
	return 0;
}
