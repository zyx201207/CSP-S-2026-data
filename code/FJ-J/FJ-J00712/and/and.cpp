#include<bits/stdc++.h>
using namespace std;
int a[2010],dp[2010][2010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dp[i][m]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m-1;j>=0;j--){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j+1]&a[i-1]); 
		} 
	}
	cout<<dp[n][0];
	return 0;
}

