#include<bits/stdc++.h>
using namespace std;
int dp[20005][20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	int max_one=-1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>max_one) max_one=a[i];
	}
	dp[0][m]=1;
	int j=m;
	for(int i=1;i<=n;i++){
		dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
	}
	cout<<dp[n][m];
	return 0;
}
