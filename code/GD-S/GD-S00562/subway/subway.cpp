#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,c,m,d,q,dp[510][510],w[500010];
vector<pair<int,int> >pos[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int temp,zt,t;
		cin>>temp;
		for(int j=1;j<=temp;j++)
			cin>>zt>>t,pos[zt].emplace_back(make_pair(i,t));
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=m;i++)
		for(auto p1:pos[i]) for(auto p2:pos[i]){
			int u=p1.first,v=p2.first,t1=p1.second,t2=p2.second;
			dp[u][v]=dp[v][u]=min(dp[u][v],t1+t2);
		}
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--){
		int l,r,ans=LLONG_MAX;
		cin>>l>>r;
		for(auto p1:pos[l]) for(auto p2:pos[r]){
			int u=p1.first,v=p2.first,t1=p1.second,t2=p2.second;
			ans=min(ans,dp[u][v]+t1+t2);
		}
		ans+=w[l]+w[r];
		cout<<ans<<'\n';
	}
	return 0;
}
