#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
typedef pair<int,int> pii; 
int c,n,m,d,q,w[N],dis[N],vis[N],b[N][N];
vector<pair<int,int> > E[533];
void djs(int sx){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=n;i++){
		int p=0;
		for(auto nx:E[i]){
			int v=nx.first,t=nx.second;
			if(v==sx){
				dis[sx]=min(dis[sx],t);
				p=t;
			}
		}
		if(p){
			for(auto nx:E[i]){
				int v=nx.first,t=nx.second;
				if(v!=sx){
					if(dis[v]>p+t){
						dis[v]=p+t;
						q.push({dis[v],v});
					}
				}
			}
		}
	}
	while(q.size()){
		int u=q.top().second;q.pop();
		b[sx][u]=w[sx]+w[u]+dis[u];
		if(vis[u]) continue;
		vis[u]=1;
		int minn=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			int p=0;
			for(auto nx:E[i]){
				int v=nx.first,t=nx.second;
				if(v==u){
					p=t;
					minn=min(minn,t);
				}
			}
			if(p){
				for(auto nx:E[i]){
					int v=nx.first,t=nx.second;
					if(v!=u){
						if(dis[v]>dis[u]+p+t){
							dis[v]=dis[u]+p+t;
							q.push({dis[v],v});
						}
					}
				}
			}
		}
		dis[u]+=minn;
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int z;
		cin>>z;
		for(int j=1;j<=z;j++){
			int x,y;
			cin>>x>>y;
			E[i].push_back({x,y});
		}
	}
	for(int i=1;i<=m;i++) djs(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<b[x][y]<<'\n';
	}
	return 0;
}
