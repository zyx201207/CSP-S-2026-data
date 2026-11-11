#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+510;

struct node{
	int w,u;
	bool operator<(const node&W)const{
		return w>W.w;
	}
};

int c,n,m,d,qq;
int sta[N],edgk[N];
vector<node> g[N];
vector<node> mp[510];
int diss[510][510];
int viss[510][510];
int visss[510][510];
int dis[510];
bool vis[510];
priority_queue<node> q;

int dij(int s,int e){
	if(s==e) return 0;
	if(visss[s][e]) return diss[s][e];
	for(int i=1;i<=n;i++)vis[i]=0,dis[i]=1e18;
	dis[s]=0;
	q.push({0,s});
//	int l=0;
	while(q.size()){
		int u=q.top().u,w=q.top().w;
//		cout<<u<<" "<<w<<"\n";
		q.pop();
//		l++;
		if(vis[u]) continue;
		vis[u]=1;
		for(int v=1;v<=n;v++){
			if(!viss[u][v]&&!visss[u][v])continue;
			if(dis[v]>dis[u]+diss[u][v]){
				dis[v]=dis[u]+diss[u][v];
				q.push({dis[v],v});
			}
		}
	}
	for(int v=1;v<=n;v++){
		diss[s][v]=diss[v][s]=dis[v];
		visss[s][v]=visss[v][s]=1;
	}
//	cout<<l<<"\n";
	return dis[e];
}

void solve(){
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)cin>>sta[i];
	
	for(int i=1;i<=n;i++){
		cin>>edgk[i];
		for(int k=1;k<=edgk[i];k++){
			int j,t;
			cin>>j>>t;
			g[j].push_back({t,i+m});
			g[i+m].push_back({t,j});
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				diss[g[i][k].u-m][g[i][j].u-m]=diss[g[i][j].u-m][g[i][k].u-m]=g[i][j].w+g[i][k].w;
				viss[g[i][k].u-m][g[i][j].u-m]=viss[g[i][j].u-m][g[i][k].u-m]=1;
			}
		}
	}
	
	
	while(qq--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				ans=min(ans,dij(g[x][i].u-m,g[y][j].u-m)+g[x][i].w+g[y][j].w);
			}
		}
		cout<<ans+sta[x]+sta[y]<<"\n";
	}

}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	int TTT=1;
//	cin>>TTT;
	while(TTT--){
		solve();
	}
}