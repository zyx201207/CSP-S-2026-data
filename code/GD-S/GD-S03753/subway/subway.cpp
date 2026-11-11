#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct node{
	long long u,v;
}; 
long long c,n,m,d,q,dp[1005][1005],w[1000005],mn[1000005];
vector<node> a[1000005];
int main(){
	ios::sync_with_stdio(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,1,sizeof(dp));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		long long k;cin>>k;
		for(int j=1;j<=k;j++){
			long long x,y;
			cin>>x>>y;
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=0;k<j;k++){
				long long x=a[i][j].u,y=a[i][k].u;
				dp[x][y]=min(dp[x][y],a[i][j].v+a[i][k].v);
				dp[y][x]=min(dp[y][x],a[i][j].v+a[i][k].v);
			}
		}
	}
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
	while(q--){
		long long ans=1e18,l,r;
		cin>>l>>r;
		for(int i=0;i<a[l].size();i++){
			for(int j=0;j<a[r].size();j++){
				int x=a[l][i].u,y=a[r][j].u;
				ans=min(ans,dp[x][y]+a[l][i].v+a[r][j].v);
			}
		}
		cout<<ans+w[l]+w[r]<<endl;
	}
} 
