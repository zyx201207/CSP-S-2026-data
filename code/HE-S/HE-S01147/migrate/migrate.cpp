#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,dp[5000][5000],a[5000],dp1[5000][5000],ans[5000][5000],o=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j) dp[j][j]=dp1[i][j]=0;
			else dp[i][j]=dp1[i][j]=1e9;
			ans[i][j]=0;
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(abs(a[j]-a[i])<=d) dp[i][j]=dp1[i][j]=abs(a[j]-a[i]);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(dp[i][k]!=1e9&&dp[k][j]!=1e9)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(dp1[i][k]!=1e9&&dp1[k][j]!=1e9&&i!=j&&i!=k&&j!=k){
				    if(dp1[i][k]+dp1[k][j]==dp[i][j]) ans[i][j]++;
					dp1[i][j]=min(dp1[i][j],dp1[i][k]+dp1[k][j]);
    	}
     	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(ans[i][j]==2) o++;
     	cout<<o/2<<'\n';
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
