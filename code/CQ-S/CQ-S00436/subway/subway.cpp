#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<pair<int,int> > g[600010];
long long dis[600010];
bool vis[600010];
void dij(int start){
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push({0,start});
	for(int i=1;i<=600000;i++) dis[i]=1e18;
	dis[start]=0;
	while(!pq.empty()){
		auto[k,u]=pq.top();
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto[v,w]:g[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int t;cin>>t;
		g[i].push_back({m+i,t});
		g[m+i].push_back({i,t});
	}
	int l=1;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		vector<pair<int,int> > p;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			p.push_back({a,l});
			g[m+a].push_back({m*2+l,t});
			g[m*2+l].push_back({m+a,t});
			l++;
		}
		for(int i=0;i<k-1;i++){
			g[p[i].second+2*m].push_back({p[i+1].second+2*m,0});
			g[p[i+1].second+2*m].push_back({p[i].second+2*m,0});
		}
		g[p[k-1].second+2*m].push_back({p[1].second+2*m,0});
		g[p[0].second+2*m].push_back({p[k-1].second+2*m,0});
	}
	for(int i=1;i<=q;i++){
		int start,end;
		cin>>start>>end;
		dij(start);
		cout<<dis[end]<<endl;
	}
	return 0;
}
