#include<bits/stdc++.h>
using namespace std;
const long long maxn=500010,maxm=1000000010;
int n,m,a[maxn],dp[maxn][maxm];
long long ans=-1000000000010;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)dp[1][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			for(int k=1;k<=i;k++){
				for(int z=1;z<=j;z++){
					dp[i][j]=max(dp[i][j],dp[k][z]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(dp[n][i]>ans)ans=dp[n][i];
	}
	cout<<ans<<endl;
	return 0;
}
