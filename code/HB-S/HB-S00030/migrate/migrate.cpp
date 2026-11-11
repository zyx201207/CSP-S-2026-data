#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,T,x[310],dp[310][310],n,d,la,j,w[310][310],ans;
void solve(){
	cin>>n>>d>>x[1];
	la=x[1],j=1,dp[1][1]=1;w[1][1]=1,ans=0;
	memset(dp,0x3f,sizeof dp);
	for(int i=2;i<=n;++i){
		cin>>x[i];
		while(x[i]-la>d) la=x[++j];
		for(int k=j;k<=i;++k){dp[i][k]=1,dp[k][i]=1;w[i][k]=1,w[k][i]=1;}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				if(i==j||j==k||i==k) continue;
				if(dp[i][j]>dp[i][k]+dp[k][j]){
					dp[i][j]=dp[i][k]+dp[k][j],dp[j][i]=dp[i][k]+dp[k][j];
					w[i][j]=1,w[j][i]=1;
				}
				else if(dp[i][j]==dp[i][k]+dp[k][j]) w[i][j]++,w[j][i]++;
			}
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=i;++j) if(w[i][j]==2) ans++;
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
