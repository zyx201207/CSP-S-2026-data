#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005],dp[20005][20005],ma=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
		dp[i][i]=a[i];
		dp[i+n][i+n]=a[i+n];
	}
	for(int l=2;l<=m;l++){
		for(int i=1;i<=n+1;i++){
			int j=i+l-1;
			for(int k=i;k<=j;k++){
				dp[i][j]=max(dp[i][j],(dp[i][k]&dp[k+1][j])&a[k]);
			}
			ma=max(ma,dp[i][j]);
		}
	}
//	for(int i=1;i<=n+1;i++){
//		for(int j=1;j<=n+1;j++){
//			cout<<dp[i][j]<<"  ";
//		}
//		cout<<endl;
//	}
	cout<<ma;
	return 0;
}