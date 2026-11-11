#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e4+5;
ll dp[N][N],a[N];//表示n个里面选m个的最大值 

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++){
		dp[i][1]=max(dp[i-1][1],a[i]);
		for(int j=2;j<=min(m,n);j++){
			dp[i][j]=max(dp[i][j],max(dp[i-1][j-1]&a[i],dp[i-1][j]));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<'\n';
	} 
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=min(m,n);j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	
	cout<<dp[n][m]<<'\n'; 
	
	return 0;
} 
