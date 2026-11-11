#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,qq;
struct edge{
	int v,w;
};
vector<edge> e[N*2+500];
struct node{
	int dis,u;
	bool operator > (const node b)const{return dis>b.dis;}
};
struct quest{
	int x,y,id;
	bool operator < (const quest b)const{return x<b.x;}
}qs[100005];
int dis[N],ans[N];
bool vis[N];
priority_queue<node,vector<node>,greater<node> > q;
void init(int s){
	while(!q.empty()){
		q.pop();
	}
	memset(dis,0x3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({0,s});
	vis[s]=1;
}
void dijkstra(int t){
	bool f=false;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		for(auto ed:e[u]){
			int v=ed.v,w=ed.w;
			if(vis[v]) continue;
			vis[v]=1;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
			if(v==t) f=1;
		}
		if(f==true) return;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		e[i].push_back({i+m,x});
		e[i+m].push_back({i,x});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int v,w;
			cin>>v>>w;
			e[i+2*m].push_back({v+m,w});
			e[v+m].push_back({i+2*m,w});
		}
	}
	for(int i=1;i<=qq;i++){
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		qs[i].x=x,qs[i].y=y,qs[i].id=i;
	}
	sort(qs+1,qs+qq+1);
	int now=0;
	for(int i=1;i<=qq;i++){
		int x=qs[i].x,y=qs[i].y,id=qs[i].id;
//		cout<<x<<' '<<y<<' '<<id<<' '<<'\n';
		if(x==now){
			if(vis[y]==true) ans[id]=dis[y];
			else dijkstra(y),ans[id]=dis[y];
		}else{
			init(x);
			now=x;
			dijkstra(y);
			ans[id]=dis[y];
		}
	}
	for(int i=1;i<=qq;i++) cout<<ans[i]<<'\n';
	return 0;
}

