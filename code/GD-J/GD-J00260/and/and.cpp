#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int dp[N][N],a[N];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	  int n,m;
       cin>>n>>m;
       for(int i=1;i<=n;i++){
       	cin>>a[i];
	   }
	   dp[1][1]=a[1];
	   for(int i=1;i<=n;i++){
	   	  for(int j=1;j<=m;j++){
	   	  	if(i<j) break;
	   	  	  dp[i][j]=max(dp[i-1][j-1] & a[i],dp[i-1][j]);
	   	  	  ans=max(ans,dp[i][j]);
			 }
	   }
	   cout<<ans;
	return 0;
} 
