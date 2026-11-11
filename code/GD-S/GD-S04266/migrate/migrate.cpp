#include<bits/stdc++.h> 
#define maxn 2000005
#define inf 2000000000000000000LL
#define ll long long
using namespace std;
ll n,d,x[maxn];
struct Edge{
	int v;ll w;
};
vector<Edge> g[maxn];
struct Node{
	int u;ll w;
	bool operator<(const Node&b)const{
		return w>b.w;
	}
};
ll res=0;
void dijkstra(int s){
	vector<ll> dis(n+1,inf);
	vector<int> ways(n+1,0);
	vector<bool> vis(n+1);
	priority_queue<Node> que;
	que.push({s,0});dis[s]=0;ways[s]=1;
	while(!que.empty()){
		int u=que.top().u;que.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto e:g[u]){
			int v=e.v;ll w=e.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				ways[v]=ways[u];
				que.push({v,dis[v]}); 
			}else if(dis[u]+w==dis[v]){
				ways[v]+=ways[u];
			}
		}
	}
	for(int i=s+1;i<=n;i++){
//		cerr<<i<<" "<<ways[i]<<"\n";
		if(ways[i]==2)res++;
	}
}
void solve(){
	cin>>n>>d;
	res=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];g[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(x[j]-x[i])<=d){
				g[i].push_back({j,1});
				g[j].push_back({i,1});
			}
		}
	}
	for(int i=1;i<=n;i++)dijkstra(i);
	cout<<res<<"\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
