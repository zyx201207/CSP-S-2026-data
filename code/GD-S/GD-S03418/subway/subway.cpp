#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=5e5+10;
int n,m,d,q,c,w[maxn],k[550],dist[550][550];
struct node{
	int v,w;
};
struct ss{
	int v,w;
	friend bool operator<(ss a,ss b){
		return b.w<a.w;
	}
};
int G[550][550];
vector<node>id[maxn],g[550];
bool vis[550][550];
void dij(int st){
	priority_queue<ss>q;
	q.push({st,0});
	while(q.size()){
		int u=q.top().v,w=q.top().w;
		q.pop();
		if(vis[st][u])continue;
		vis[st][u]=1;
		for(auto v:g[u]){
			if(vis[st][v.v])continue;
			if(dist[st][v.v]>w+v.w){
				dist[st][v.v]=w+v.w;
				q.push({v.v,dist[st][v.v]});
			}
		}
	}
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int now,t;
			cin>>now>>t;
			id[now].push_back({i,t});
		}
	}
	memset(G,0x3f,sizeof G);
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=m;i++){
		for(int x=0;x<id[i].size();x++){
			for(int y=x+1;y<id[i].size();y++){
				int u=id[i][x].v,v=id[i][y].v;
				int w=id[i][x].w+id[i][y].w;
				G[u][v]=G[u][v]=min(G[u][v],w);
			}
		}
	}
	//目前2e8 
	for(int i=1;i<=n;i++){
		dist[i][i]=0;
		for(int j=i+1;j<=n;j++){
			if(i==j||G[i][j]>=inf)continue;
			g[i].push_back({j,G[i][j]});
			g[j].push_back({i,G[i][j]});
		}
	}
	//跑最短路
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(auto st:id[x]){
			for(auto en:id[y]){
				if(min(dist[st.v][en.v],dist[en.v][st.v])<inf){
					ans=min(min(dist[st.v][en.v],dist[en.v][st.v])+st.w+en.w,ans);	
					continue;
				}
				dij(st.v);
				ans=min(min(dist[st.v][en.v],dist[en.v][st.v])+st.w+en.w,ans);
			}
		}
		cout<<w[x]+w[y]+ans<<"\n";
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
