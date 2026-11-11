#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN=500,MAXM=5e5,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[MAXM+5];
vector<pair<int,int>> sta[MAXN+5];
vector<pair<int,int>> line[MAXM+5];
int dist[MAXN+5][MAXN+5];

void dijkstra(int s){
	fill(dist[s]+1,dist[s]+n+1,INF); dist[s][s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> h; h.push({dist[s][s],s});
	while(!h.empty()){
		int d=h.top().first,u=h.top().second; h.pop();
		if(d>dist[s][u]) continue;
		for(auto st:sta[u]){
			int x=st.first,t1=st.second;
			for(auto ln:line[x]){
				int v=ln.first,t2=ln.second;
				if(v==u) continue;
				if(dist[s][u]+t1+t2<dist[s][v]){
					dist[s][v]=dist[s][u]+t1+t2;
					h.push({dist[s][v],v});
				}
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k; cin>>k;
		for(int j=1;j<=k;++j){
			int a,t; cin>>a>>t;
			sta[i].push_back({a,t});
			line[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i) dijkstra(i);
	while(q--){
		int x,y; cin>>x>>y;
		int res=INF;
		for(auto ln1:line[x]){
			int u=ln1.first,t1=ln1.second;
			for(auto ln2:line[y]){
				int v=ln2.first,t2=ln2.second;
				res=min(res,w[x]+t1+dist[u][v]+t2+w[y]);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
