#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
struct node{int x,y;};
int c,n,m,d,q,w[M],dp[N][N],k,x,y,ans;
vector<node> T[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(dp,0x3f,sizeof dp);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i = 1;i<=n;i++){
		cin>>k,dp[i][i]=0;
		for(int j = 1;j<=k;j++)
			cin>>x>>y,T[x].push_back({i,y});
	}
	for(int i = 1;i<=m;i++)
		for(node j:T[i])
			for(node k:T[i])
				dp[j.x][k.x]=min(dp[j.x][k.x],j.y+k.y);
	for(int k = 1;k<=n;k++)
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
//	for(int i = 1;i<=n;i++){
//		cout<<"i:"<<i<<' ';
//		for(int j = 1;j<=n;j++) cout<<dp[i][j]<<' ';cout<<'\n';
//	}
	while(q--){
		cin>>x>>y;
		ans=1e18;
		for(node i:T[x])
			for(node j:T[y])
				ans=min(ans,w[x]+w[y]+i.y+j.y+dp[i.x][j.x]);
		cout<<ans<<'\n';
	}
	return 0;
}
