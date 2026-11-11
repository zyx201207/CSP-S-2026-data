#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int a[N],dp[N][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=a[1];
	//memset(dp,-0x3f,sizeof(dp));
	dp[1][1]=a[1];
	for(int i=2;i<=n;i++){
		dp[i][i]=(dp[i-1][i-1]&a[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]>maxn){
			dp[i][1]=a[i];
			maxn=a[i];
		}else{
			dp[i][1]=maxn;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m&&j<i;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);				
			
		}
	}
	cout<<dp[n][m];
	return 0;
}
