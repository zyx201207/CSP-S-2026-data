#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5000005;
int csdbh,n,m,d,dis[M],qqq,len[N],w[M],st,ed,t[50005][505];//n:线路数量 m:站数量 d:每个地铁站最多被几条线路经过 
bool vis[M];
vector<int>a[N];
struct EDGE{
	int to;
	int dis;
};
struct node{
	int id;
	int dis;
	bool operator > (const node &other)const{
		return dis>other.dis;
	} 
};
vector<vector<EDGE> >g;
priority_queue<node,vector<node>,greater<node> >q;
inline void dijkstra(int st){
	for(int i=1;i<=m;i++)dis[i]=LLONG_MAX,vis[i]=0;
	dis[st]=0;
	q.push({st,0});
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(EDGE i:g[u]){
			if(dis[u]+i.dis<dis[i.to]){
				dis[i.to]=dis[u]+i.dis;
				q.push({i.to,dis[i.to]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>csdbh>>n>>m>>d>>qqq;
	g.resize(m+1);
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(t,-1,sizeof t);
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1,k;j<=len[i];j++){
			cin>>k>>t[k][i];
			a[i].push_back(k);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0,u,v,w;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				u=a[i][j];
				v=a[i][k];
				w=t[u][i]+t[v][i];
				g[u].push_back({v,w});
				g[v].push_back({u,w});
			}
		}
	}
	while(qqq--){
		cin>>st>>ed;
		dijkstra(st);
		cout<<dis[ed]+w[st]+w[ed]<<'\n';
	}
	return 0;
}
