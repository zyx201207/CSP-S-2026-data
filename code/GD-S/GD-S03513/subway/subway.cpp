#include<bits/stdc++.h>
using namespace std;
const int N=50+5;
const int M=5*1e5+5;
const int inf=1e9;

int c,n,m,d,q;
int w[M];
int k,a,t;
int x,y;

//struct subline{
//	int k;
//	int a[M],t[M];
//}sl[N];

struct edge{int v,w;};

vector<edge> mp[N+M];

int dis[N+M];
int vis[N+M];
void dijkstra(int x,int y){
	priority_queue<pair<int,int>> q;
	for(int i=1;i<N+M;i++) dis[i]=inf,vis[i]=0;
	q.push({0,x});
	while(!q.empty()){
		int d=q.top().first;
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		dis[u]=-1*d;
		vis[u]=1;
		for(int i=0;i<mp[u].size();i++){
			int v=mp[u][i].v;
			int w=mp[u][i].w;
			q.push({d-w,v});
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
//		sl[i].k=k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
//			sl[i].a[j]=a;
//			sl[i].t[j]=t;
			mp[i+m].push_back({a,t});
			mp[a].push_back({i+m,t});
		}
	}
	while(q--){
		cin>>x>>y;
		dijkstra(x,y);
		cout<<w[x]+w[y]+dis[y]<<endl;
	}
	return 0;
}
