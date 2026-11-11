#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,a[2000010],dp[510][510],update[510][510];
signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		memset(dp,0x3f,sizeof dp);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) update[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(a[j]-a[i]<=d&&a[j]-a[i]>=-d) dp[i][j]=dp[j][i]=1;
		for(int i=1;i<=n;i++) dp[i][i]=0;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					if(dp[i][j]>dp[i][k]+dp[k][j])
						dp[i][j]=dp[i][k]+dp[k][j],update[i][j]=1;
					else if(dp[i][j]==dp[i][k]+dp[k][j]&&dp[i][k]&&dp[k][j])
						update[i][j]++;
				}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
			ans+=(update[i][j]==2);
		cout<<ans/2<<'\n';
	}
}
