#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
long long dp[6005][6005],n,m,a[N];
int main(){
	for(long long i=0;i<=6000;i++){
		for(long long j=0;j<=6000;j++){
				dp[i][j]=1;
		}
	}
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(abs(a[i]-a[i-1])<=j&&i>2){
				dp[i][j]=max(dp[i][j],dp[i-1][j-abs(a[i]-a[i-1])]+1);
			}
		}
	}
	/*for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}*/
	cout<<dp[n][m];
	return 0;
}
