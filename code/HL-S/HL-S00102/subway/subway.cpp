#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+5;
const int M=1e6+5;
int c,n,m,d,q;
struct edge{
	int to,nxt,dis;
}e[M];
int head[N],I;
int w[N];
void add_edge(int u,int v,int dis){
	e[++I]={v,head[u],dis};
	head[u]=I;
}
//struct Query{
//	int u,v,idx;
//}que[N];
//int ans[N];
//bool cmp(Query a,Query b){
//	return a.u<b.u;
//}
int vis[N],dist[N];
void dijkstra(int s){
	for(int i=1;i<=n+m;i++)vis[i]=0,dist[i]=3e18;
	dist[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to,dis=e[i].dis;
			if(dist[v]>dist[u]+dis)dist[v]=dist[u]+dis,q.push({dist[v],v});
		}
	}
}
int dd[505][505];
int zt[N][25];
int t[N][25];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,dis;
			cin>>v>>dis;
			zt[v][++zt[v][0]]=i;
			t[v][zt[v][0]]=dis;
			add_edge(v,i+m,dis);
			add_edge(i+m,v,dis);
		}
	}
//	int now=time(0);
	for(int i=1;i<=n;i++){
		dijkstra(i+m);
		for(int k=1;k<=n;k++){
			dd[i][k]=dist[k+m];
		}
	}
//	cerr<<time(0)-now<<'\n';
//	for(int i=m+1;i<=m+n;i++){
//		for(int j=m+1;j<=m+n;j++){
//			cout<<dd[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	for(int i=1;i<=n;i++){
//		cout<<zt[i][0]<<' ';
//	}
//	cout<<'\n';
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=3e18;
		for(int i=1;i<=zt[u][0];i++){
			for(int j=1;j<=zt[v][0];j++){
				
				ans=min(ans,dd[zt[u][i]][zt[v][j]]+t[u][i]+t[v][j]);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
//	for(int i=1;i<=q;i++){
//		cin>>que[i].u>>que[i].v;
//		que[i].idx=i;
//		if(que[i].u<que[i].v)swap(que[i].u,que[i].v);
//	}
//	sort(que+1,que+1+q,cmp);
//	int lst=0;
//	for(int i=1;i<=q;i++){
//		if(que[i].u==lst)ans[que[i].idx]=dist[que[i].v]+w[que[i].u]+w[que[i].v];
//		else{
//			dijkstra(que[i].u);
//			ans[que[i].idx]=dist[que[i].v]+w[que[i].u]+w[que[i].v];
//		}
//	}
//	for(int i=1;i<=q;i++){
//		cout<<ans[i]<<'\n';
//	}
	return 0;
}
// I love Skirk
//4:1.926s
//5:1.205s
//6:T
//16:00:54 T2 (force) finished
//17:21:20 faster_force