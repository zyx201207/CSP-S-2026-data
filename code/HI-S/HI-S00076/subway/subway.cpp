#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e6+5,N=5e5+5,INF=1e18;
struct FowardStar{
	int to[M*2],nxt[M*2],w[M*2],cnt,head[N];
	void add_edge(int u,int v,int val){
		to[++cnt]=v;
		nxt[cnt]=head[u];
		w[cnt]=val;
		head[u]=cnt;
		return;
	}
	void add(vector<int>g,vector<int>w){
		for(int i=0;i<g.size()-1;i++)
			for(int j=i+1;j<g.size();j++){
				add_edge(g[i],g[j],w[i]+w[j]);
				add_edge(g[j],g[i],w[i]+w[j]);
			}
		return;
	}
}e; 
int c,n,m,D,q,w[N];
void init(){
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,u,w;
		vector<int>g,t; 
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>u>>w;
			g.push_back(u);
			t.push_back(w); 
		}
		e.add(g,t);
	}
	return;
}
ll d[1005][1005];
struct Point{
	int u,dis;
	Point(){}
	Point(int _u,int _d):u(_u),dis(_d){}
	bool operator<(Point r)const{
		return dis>r.dis;
	} 
};
void dijkstra(int s){
	for(int i=1;i<=m;i++)d[s][i]=INF;
	d[s][s]=0;
	priority_queue<Point>q;
	q.push(Point(s,0));
	while(!q.empty()){
		int u=q.top().u,dis=q.top().dis;
		q.pop();
		if(d[s][u]!=dis)continue;
		for(int i=e.head[u];i;i=e.nxt[i]){
			int v=e.to[i],w=e.w[i];
			if(d[s][v]>d[s][u]+w){
				d[s][v]=d[s][u]+w;
				q.push(Point(v,d[s][v]));
			}
		}
	} 
	return;
}
ll dis[N];
void dijkstra2(int s,int t){
	for(int i=1;i<=m;i++)dis[i]=INF;
	dis[s]=0;
	priority_queue<Point>q;
	q.push(Point(s,0));
	while(!q.empty()){
		int u=q.top().u,d=q.top().dis;
		q.pop();
		if(dis[u]!=d)continue;
		for(int i=e.head[u];i;i=e.nxt[i]){
			int v=e.to[i],w=e.w[i];
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(Point(v,dis[v]));
			}
		}
	} 
	cout<<dis[t]+w[s]+w[t]<<"\n";
	return;
}
void solve(){
	int s,t;
	cin>>s>>t;
	if(m>1000){
		dijkstra2(s,t);
		return;
	}
	if(d[s][t]){
		cout<<d[s][t]+w[s]+w[t]<<"\n";
		return;
	}
	dijkstra(s);
	cout<<d[s][t]+w[s]+w[t]<<"\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	while(q--)solve();
	return 0;
}
//score: about 40 points
