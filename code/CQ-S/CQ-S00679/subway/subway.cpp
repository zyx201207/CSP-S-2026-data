#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int cid,n,m,D,q,w[N];
vector<pair<int,int>> G[N];
#define ll long long
ll dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>cid>>n>>m>>D>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			G[x].push_back({y,i});
		}
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j) if(i!=j) dis[i][j]=1ll<<60;
	for(int i=1;i<=m;++i){
		for(int j=0;j<(int)G[i].size();++j){
			int x=G[i][j].second;
			for(int k=j+1;k<(int)G[i].size();++k){
				int y=G[i][k].second;
				dis[x][y]=min(dis[x][y],(ll)G[i][j].first+G[i][k].first);
			}
		}
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j) dis[i][j]=min(dis[i][j],dis[j][i]);
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1ll<<60;
		for(auto u:G[x])
		for(auto v:G[y]) ans=min(ans,u.first+v.first+dis[u.second][v.second]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

