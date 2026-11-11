#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int sum=0;
//	if(m==n-1){
//		
//	}
	for(int i=1;i<=n;i++){cin>>a[i];dp[i][1]=max(dp[i-1][1],a[i]);}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(j>i)continue;
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]); 
		}
	}
	int maxx=0;
	for(int i=m;i<=n;i++){
		maxx=max(maxx,dp[i][m]);
	}
	cout<<maxx;
	return 0;
}
//4 2 3 15 12 12
//5 3 31 3 1 15 7
