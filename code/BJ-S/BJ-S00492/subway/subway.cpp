#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=1e6+5;
int c,n,m,d,q;
long long valw[M];
vector<pair<int,long long> > val[M],g[M];
void add(int u,int v,long long w){
	g[u].push_back({v,w}),g[v].push_back({u,w});
}
struct node{
	long long x,key;
	bool operator <(const node &b)const{
		return key>b.key;
	}
};
priority_queue<node> pq;
long long dis[N][N],vis[N];
void dijkstra(int s){
	for(int i=1;i<=n;i++) dis[s][i]=2e18,vis[i]=0;
	pq.push(node{s,0}),dis[s][s]=0;
	while(!pq.empty()){
		int u=pq.top().x;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		int len=g[u].size();
		for(int i=0;i<len;i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				pq.push(node{v,dis[s][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>valw[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			val[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int len=val[i].size();
		for(int x=0;x<len;x++){
			for(int y=x+1;y<len;y++){
				add(val[i][x].first,val[i][y].first,val[i][x].second+val[i][y].second);
			}
		}
	}
	for(int i=1;i<=n;i++) dijkstra(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<'\n';
			continue;
		}
		long long ans=2e18;
		int lenx=val[x].size(),leny=val[y].size();
		for(int u=0;u<lenx;u++){
			for(int v=0;v<leny;v++){
				int i=val[x][u].first,tx=val[x][u].second;
				int j=val[y][v].first,ty=val[y][v].second;
				ans=min(ans,tx+ty+dis[i][j]);
			}
		}
		cout<<ans+valw[x]+valw[y]<<'\n';
	}
	return 0;
}
