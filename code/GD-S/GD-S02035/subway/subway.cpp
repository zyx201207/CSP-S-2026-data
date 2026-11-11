#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXM=5e5+8;
const int MAXN=508;	
const ll inf=0x3f3f3f3f;
int c,n,m,d,q;
int w[MAXM],k[MAXN];
struct edge{
	int v,w;
};
struct node{
	int dis,u;
	bool operator > (const node &x) const{
		return dis>x.dis;
	}
};
vector<edge> edges[MAXN];
int dis[MAXM];
bool vis[MAXM];
priority_queue<node,vector<node>,greater<node>> qp; 
void dijkstra(int s){
	fill(vis+1,vis+m+1,0);
	dis[s]=0;
	qp.push({s,0});
	while(!qp.empty()){
		int u=qp.top().u;
		qp.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ed:edges[u]){
			int v=ed.v,w=ed.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				qp.push({dis[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			edges[a].push_back({a,t});
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<rand();
	}
	return 0;
}

