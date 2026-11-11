#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200010];
int f[200010][1010];//在前 i 个数中选 j 个且必选第 i 个时的最大值 
int dp[200010][1010];//在前 i 个数中选 j 个时的最大值 


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	for(int i=1;i<=n;i++){
		f[i][1]=a[i];
		dp[i][1]=max(a[i],dp[i-1][1]);
//		cout<<f[i][1]<<' ';
		for(int j=2;j<=m;j++){
			f[i][j]=dp[i-1][j-1]&a[i];
			dp[i][j]=max(max(dp[i-1][j-1]&a[i],dp[i-1][j]),max(f[i-1][j],f[i-1][j-1]&a[i]));
//			cout<<f[i][j]<<' ';
		}
//		cout<<"\n";
	}
	cout<<dp[n][m];
	return 0;
}
