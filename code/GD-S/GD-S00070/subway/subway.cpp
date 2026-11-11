#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	int mp[1005][1005];long long dp[1005];bool vis[1005];
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a1,t1,a2,t2;
		cin>>a1>>t1>>a2>>t2;
		mp[a1][a2]=t1+t2;
		mp[a2][a1]=t1+t2;
	}
	while (q--){
		int x,y;
		cin>>x>>y;
		int end=x;
		vis[x]=1;
		memset(dp,0,sizeof(dp));
		while (end!=y){
			for (int i=1;i<=m;i++){
				if (mp[end][i]&&!vis[i]){
					dp[i]=dp[end]+mp[end][i];
					end=i;
					vis[i]=1;
					break;
				}
			}
		}
		memset(vis,0,sizeof(vis));
		while (end!=y){
			for (int i=m;i>=1;i--){
				if (mp[end][i]&&!vis[i]){
					dp[i]=min(dp[i],dp[end]+mp[end][i]);
					end=i;
					vis[i]=1;
					break;
				}
			}
		}
		cout<<dp[y]+w[x]+w[y];
	}
	return 0;
} 
