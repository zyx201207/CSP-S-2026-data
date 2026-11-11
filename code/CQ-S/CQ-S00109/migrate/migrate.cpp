#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[5005],dp[5005][5005],f[5005][5005],vis[5005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=i;
			memset(vis,0,sizeof(vis));
			vis[0]=1;
			f[i][i]=0;
			for(int j=i+1;j<=n;j++){
				while(j>l&&a[j]-a[l]>d)vis[dp[i][l]]-=f[i][l],l++;
				if(l!=j){
					dp[i][j]=dp[i][l]+1;
					f[i][j]=vis[dp[i][l]];
					vis[dp[i][j]]+=f[i][j];
					if(vis[dp[i][l]]==2)ans++;					
				}else{
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

