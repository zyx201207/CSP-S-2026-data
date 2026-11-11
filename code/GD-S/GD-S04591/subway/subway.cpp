#include<bits/stdc++.h>
#define int long long
using namespace std;

int w[500005],dis[505][505];
vector<pair<int,int> > dot[500005],g[505];

void dij(int i){
	priority_queue<pair<int,int> > q;
	q.push({0,i});
	dis[i][i]=0;
	while(!q.empty()){
		int u=q.top().second,t=q.top().second;q.pop();
		for(auto x:g[u]){
			int v=x.first,w=x.second;
			if(dis[i][u]+w<dis[i][v]){
				dis[i][v]=dis[i][u]+w;
				q.push({-w,v});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			dot[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(auto u:dot[i]){
			for(auto v:dot[i]){
				if(u==v)continue;
				int nu=u.first,nv=v.first,w=u.second+v.second;
				g[nu].push_back({nv,w});
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dij(i);
	}
	
	for(int i=1;i<=q;i++){
		int res=9e18;
		int u,v;
		cin>>u>>v;
		for(auto x:dot[u]){
			for(auto y:dot[v]){
				res=min(res,dis[x.first][y.first]+x.second+y.second+w[u]+w[v]);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
} 

