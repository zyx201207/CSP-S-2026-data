#include<bits/stdc++.h>

using namespace std;
const int N=1e4+10;
int n,m,a[N],dp[N][N],ans,ma,mx;//从前i个选出j个的最大值 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1]=a[i];
		ma=max(ma,a[i]);
		if(i==1) mx=a[1];
		if(i>1) mx=mx&a[i];
	}
	if(m==1) return cout<<ma,0;
	if(m==n) return cout<<mx,0;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(j<=i)
			dp[i][j]=max(dp[i][j],dp[i][j-1]&dp[i-1][j-1]);
		}
	}
	for(int i=1;i<=n;i++) ans=max(ans,dp[i][m]);
	cout<<ans;
	return 0;
}
//4 2
// 3 15 12 12
//5 2
//31 3 1 15 7
