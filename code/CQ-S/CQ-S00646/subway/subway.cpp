#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const ll inf=1e18;
struct edge{
	int v;
	ll w;
};
vector<edge>g[N+505];
struct node{
	int t;
	ll dis;
	bool friend operator <(const node &a,const node &b){
		return a.dis>b.dis;
	}
};
ll w[N],dis[N+505];
bool vis[N+505];
int n,m;
void dijkstra(int s){
	for(int i=1;i<=m+n;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	dis[s]=0;
	priority_queue<node>pq;
	pq.push(node{s,0});
	while(!pq.empty()){
		int u=pq.top().t;
		pq.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(auto i:g[u]){
			int v=i.v;
			ll w=i.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					pq.push(node{v,dis[v]});
				}
			}
		}
	}
}
int main(){
	//应该能有分，CCF求求您了多给点吧！
	//少的话40pts，多的话能有55pts，评测机性能够好说不定75pts
	//CCF求您了！ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			ll t;
			cin>>a>>t;
			g[a].push_back(edge{m+i,t});
			g[m+i].push_back(edge{a,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
} 
//地铁是双向任意通行
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/ 
