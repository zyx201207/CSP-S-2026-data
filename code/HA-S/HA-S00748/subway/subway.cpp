#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
#define ull unsigned long long
#define inf 10000000000000ll
int c,n,m,d,q;
ll dp[500][500],w[N];
vector<pair<int,ll>>pos[N];
void solve(){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dp[i][j]=inf;
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int to;
			ll tim;
			cin>>to>>tim;
			pos[to].push_back({i,tim});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:pos[i]){
			for(auto k:pos[i]){
				int u=j.first,v=k.first;
				ll val1=j.second,val2=k.second;
				dp[u][v]=min(dp[u][v],val1+val2);
				dp[v][u]=min(dp[v][u],val1+val2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=inf,base=w[u]+w[v];
		for(auto i:pos[u]){
			for(auto j:pos[v]){
				int a=i.first,b=j.first;
				ll val=dp[a][b];
				ans=min(ans,base+i.second+j.second+val);
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	solve();
	return 0;
}
//把每条线路看成一个点，o(qd^2)
//ans=wi+wj+min(i所属的线路到j所属的线路) 
