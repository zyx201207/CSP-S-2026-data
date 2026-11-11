#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2000005],ca,T,b[2000005],d,dp[5005][5005],ans,vis[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>ca>>T;
	while(T--){
		cin>>n>>d;ans=0;
		memset(dp,0x3f3f,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=5000){
			for(int i=1;i<=n;i++){
				for(int l=1;l+i-1<=n;l++){
					int r=l+i-1;
					if(l==r) dp[l][r]=0,vis[l][r]=0;
					else if(a[r]-a[l]<=d) dp[l][r]=1,vis[l][r]=1;
					else{
						int cnt=0;
						for(int k=l+1;k<r;k++){
							if(a[r]-a[k]<=d){
								if(dp[l][r]>dp[l][k]+1) dp[l][r]=dp[l][k]+1,cnt=vis[l][k];
								else if(dp[l][r]==dp[l][k]+1) cnt+=vis[l][k];
							}
						}
						if(cnt==2) ans++;
						vis[l][r]=cnt;
					}
				}
			}
			cout<<ans<<'\n';
		}else cout<<0<<'\n';
	}
	return 0;
}
