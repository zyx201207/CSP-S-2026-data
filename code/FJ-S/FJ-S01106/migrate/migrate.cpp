#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010],dp[301][301],dp2[301][301],vis[301],cha[301],d;
void solve(){
	memset(vis,0,sizeof vis);
	memset(cha,0,sizeof cha);
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) cha[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++) if(cha[i]>d) vis[i]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=2e18,dp2[i][j]=0;
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			
				bool fa=1;
				for(int k=i;k<j;k++) if(vis[k]) fa=0;
				if(!fa) continue;
				if(a[j]-a[i]<=d){
					dp[i][j]=1;
					dp2[i][j]=1;
					continue;
				}
				for(int k=i+1;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]); 
				for(int k=i+1;k<j;k++) if(dp[i][k]+dp[k][j]==dp[i][j]) dp2[i][j]++;
		}
	} 
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(dp2[i][j]==2) ans++;
//	for(int i=1;i<=n;i++,cout<<endl) for(int j=1;j<=n;j++) cout<<dp[i][j]<<" ";
//	for(int i=1;i<=n;i++,cout<<endl) for(int j=1;j<=n;j++) cout<<dp2[i][j]<<" ";
	cout<<ans<<endl; 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
int c,t;
cin>>c>>t;
while(t--) solve();
}

