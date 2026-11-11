#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,m;
int si[500],dp[305][305],dp2[305][305],vis[305][305],pp[305][305];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>si[i];
		memset(dp,0x3f,sizeof(dp));
		memset(dp2,0x3f,sizeof(dp2));
		memset(pp,0,sizeof(pp));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(si[i]-si[j])<=d&&i!=j) {
					dp[i][j]=abs(si[i]-si[j]);
					dp[j][i]=abs(si[i]-si[j]);
					dp2[i][j]=abs(si[i]-si[j]);
					dp2[j][i]=abs(si[i]-si[j]);
					pp[i][j]=1;
					pp[j][i]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				
				if(i!=j&&i!=k&&j!=k&&pp[i][k]&&pp[k][j]){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
			}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i!=j&&pp[i][j]){
					vis[i][j]++;
					
				}
				if(i!=j&&j!=k&&i!=k&&pp[i][k]&&pp[k][j]){
					dp2[i][j]=min(dp2[i][j],dp2[i][k]+dp2[k][j]);
					if(dp2[i][k]+dp2[k][j]==dp[i][j]){
						vis[i][j]++;
					}
				}
			}
		}
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
        	//cout<<i<<" "<<j<<" "<<vis[i][j]<<'\n';
        	if(vis[i][j]==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
