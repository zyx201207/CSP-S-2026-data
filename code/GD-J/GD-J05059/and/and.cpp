#include<bits/stdc++.h>
using namespace std;
const int MAXX=200005;
int a[MAXX],n,m,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	k=pow(2,31)-1LL;
	if(n==m){
		for(int i=1;i<=n;i++){
			k=k&a[i];
		}
		cout<<k;
		return 0;
	}
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		dp[i][0]=k;	
	}
	for(int i=1;i<=n;i++){
		for(int j=min(i,m);j>=1;j--){
			dp[i][j]=max(dp[i-1][j-1] & a[j],dp[i-1][j]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
