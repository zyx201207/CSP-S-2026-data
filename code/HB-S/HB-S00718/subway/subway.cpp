#include<bits/stdc++.h>
#define ll long long
using namespace std;
const unsigned long long RP=ULONG_LONG_MAX;
int csd,n,m,d,q,a[500010];
ll b[510][510];
vector<pair<int,ll> > g[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>csd>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		while(t--){
			int u,w;
			cin>>u>>w;
			g[u].push_back({i,w});
		}
	}
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int u=g[i][j].first,v=g[i][k].first;
				ll w=g[i][j].second+g[i][k].second;
				b[u][v]=min(b[u][v],w);
				b[v][u]=min(b[v][u],w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		b[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				int u=g[x][i].first,v=g[y][j].first;
				ll w=g[x][i].second+g[y][j].second;
				ans=min(ans,b[u][v]+w);
			}
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}
//diff subway.out subway4.ans ∅
//zhe xia wan le,wang ji zui duan lu ke yi yong dijkstra le,jie guo yong de floyd,ccf lao nian ji 1.75e8 bu yi ding neng pao guo qu
