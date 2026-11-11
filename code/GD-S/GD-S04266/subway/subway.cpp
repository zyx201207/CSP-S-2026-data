#include<bits/stdc++.h> 
#define maxn 505
#define maxm 500005
#define inf 1000000000000000LL
#define ll long long
// inf = 1e15
using namespace std;
int c,n,m,d,q;
ll wm[maxm],k[maxn];
vector<pair<int,ll>> con[maxm];
struct Edge{
	int v;ll w;
};
vector<Edge> g[maxm+maxn];
ll disx[maxn][maxn];
ll dis[maxn+maxm];
bool vis[maxn+maxm];
struct Node{
	int u;ll w;
	bool operator<(const Node&b)const{
		return w>b.w;
	}
};
void dijkstra(const int& s){
	for(int i=1;i<=m+n;i++){
		dis[i]=inf;vis[i]=0;
	}
	priority_queue<Node> que;
	que.push({m+s,0});dis[m+s]=0;
	while(!que.empty()){
		int u=que.top().u;que.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto e:g[u]){
			int v=e.v;ll w=e.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				que.push({v,dis[v]}); 
			}
		}
	}
	for(int i=1;i<=n;i++){
		disx[s][i]=dis[m+i];
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>wm[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;ll t;cin>>x>>t;
			g[x].push_back({m+i,t});
			g[m+i].push_back({x,t});
			con[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)dijkstra(i);
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		ll res=inf;
		for(auto a:con[x]){
			for(auto b:con[y]){
				ll ans=disx[a.first][b.first]+a.second+b.second+wm[x]+wm[y];
				res=min(res,ans);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
