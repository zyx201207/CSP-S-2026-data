#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e4+10;
struct node{
	int v,id,w;
	bool operator<(const node &other) const{
		return w>other.w;
	}
};
int w[N],n,m,c,d,q,road[N][30],cnt[N],dis[N][30];
bool vis[N][30];
vector<node> g[N][30];
void dijkstra(int s,int t){
	for(int i=1;i<=m;i++)
		for(int j=0;j<=cnt[i];j++)
			dis[i][j]=1e17,vis[i][j]=false;
	priority_queue<node> q;
	q.push({s,0,0});
	dis[s][0]=0;
	while(!q.empty()){
		int u=q.top().v;
		int id=q.top().id;
		int w=q.top().w;
		q.pop();
		if(vis[u][id]) continue;
		vis[u][id]=true;
		if(u==t && id==0) break;
		for(auto e:g[u][id])
			if(!vis[e.v][e.id] && dis[e.v][e.id]>dis[u][id]+e.w){
				dis[e.v][e.id]=dis[u][id]+e.w;
				q.push({e.v,e.id,dis[u][id]+e.w});
			}
	}
}
signed main(){
//	int st=clock();
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int k,a,t,lst=0,cntlst=0;
	for(int i=1;i<=n;i++){//线路 
		cin>>k;
		lst=0,cntlst=0;
		for(int j=1;j<=k;j++){//第几站 
			cin>>a>>t;
			cnt[a]++;
			road[a][cnt[a]]=i;//a的第cnt[a]条线是i 
			g[a][0].push_back({a,cnt[a],t});
			g[a][cnt[a]].push_back({a,0,t});
			if(lst)
				g[lst][cntlst].push_back({a,cnt[a],0}),
				g[a][cnt[a]].push_back({lst,cntlst,0});
			lst=a,cntlst=cnt[a];
		}
	}
	int mx=0;
	for(int i=1;i<=m;i++) mx=max(mx,cnt[i]);
	d=mx;
	int x,y;
	while(q--){
		cin>>x>>y;
		dijkstra(x,y);
		cout<<dis[y][0]+w[x]+w[y]<<endl;
	}
//	int ed=clock();
//	cerr<<ed-st<<endl;
	return 0;
}
