#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int MAXM=500005;
int c,n,m,d,q,w[MAXM],k,a,ti,x,y,t[505][505],dis[MAXM];
vector<pair<int,int>>g[MAXM],e[MAXM];
bool vis[MAXM];
void dijkstra(int s){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=w[s];
	q.push({w[s],s});
	while(!q.empty()){
		auto p=q.top();
		int l=p.first,u=p.second;
		q.pop();
		if(vis[u]){
			continue;
		}vis[u]=1;
		for(auto pp:e[u]){
			int w=pp.first,v=pp.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k;
		int last;
		for(int j=1;j<=k;j++){
			int ti;
			cin>>a>>ti;
			if(j!=1){
				g[last].push_back({a,i});
			}last=a;
			t[i][a]=ti;
		}
	}for(int i=1;i<=m;i++){
		if(g[i].size()>1){
			for(auto p:g[i]){
				int v=p.first,id=p.second;
				e[i].push_back({t[id][i],v});
				e[v].push_back({t[id][v],i});
			}
		}else{
			for(auto p:g[i]){
				int v=p.first,id=p.second;
				e[i].push_back({0,v});
			}
		}
	}while(q--){
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]<<'\n';
	}return 0;
}
