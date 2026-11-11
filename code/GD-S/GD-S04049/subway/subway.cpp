#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
int _c,n,m,d,q;
int w[500005],k[505];
vector<pair<int,int> >stt[500005];
vector<pair<int,int> >g[505];
int dis[505][505];
void solve(){
	cin>>_c>>n>>m>>d>>q;
	for (int i=1;i<=m;cin>>w[i++]);
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			stt[a].push_back({i,t});
		}
	}
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)if (i!=j)dis[i][j]=1e18;
	for (int i=1;i<=m;i++){
		for (int u=0;u<stt[i].size();u++){
			for (int v=u+1;v<stt[i].size();v++){
				int uu=stt[i][u].fi,vv=stt[i][v].fi;
				dis[uu][vv]=dis[vv][uu]=min(dis[uu][vv],stt[i][u].se+stt[i][v].se);
			}
		} 
	}
	for (int kk=1;kk<=n;kk++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if (u==v){
			cout<<"0\n";
			continue;
		}
		int ans=1e18;
		for (auto&i:stt[u]){
			for (auto&j:stt[v]){
				ans=min(ans,w[u]+w[v]+i.second+j.second+dis[i.first][j.first]);
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
//	freopen("C:\\Users\\Administrator\\Desktop\\subway\\subway7.in","r",stdin);
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	solve();
	return 0;
}
