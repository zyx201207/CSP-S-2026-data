#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+15,M=1005;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct Node {
	int y;
	ll val;
	bool operator < (const Node A) const {
		return val>A.val;
	}
};
int c,n,m,d,tim,k[M],x,vis[M],u,v;
int hd[N],nxt[N],to[N],len;
ll a[N],y,val[N],dis[M][M];
priority_queue <Node> q;
vector <Node> vec[N];
void dijkstra (int s,int num) {
	for(int i=1;i<=n;i++) {
		dis[num][i]=INF;
		vis[i]=false;
	}
	dis[num][s]=0ll;
	while(!q.empty()) {
		q.pop();
	}
	q.push((Node){s,0ll});
	while(!q.empty()) {
		Node Tmp=q.top();
		q.pop();
		int x=Tmp.y;
		if(vis[x]) {
			continue;
		}
		vis[x]=true; 
		for(int i=hd[x];i;i=nxt[i]) {
			int y=to[i];
			ll v=val[i];
			if(dis[num][y]>dis[num][x]+v) {
				dis[num][y]=dis[num][x]+v;
				q.push((Node){y,dis[num][y]});
			}
		}
	}
	
}
void adde (int u,int v,ll w) {
	nxt[++len]=hd[u];
	hd[u]=len;
	to[len]=v;
	val[len]=w;
}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>tim;
	for(int i=1;i<=m;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			cin>>x>>y;
			vec[x].push_back((Node){i,y});
		}
	}
	for(int i=1;i<=m;i++) {
		for(int p=0;p<(int)vec[i].size();p++) {
			Node tmpa=vec[i][p];
			for(int q=0;q<(int)vec[i].size();q++) {
				Node tmpb=vec[i][q];
				if(p==q) {
					continue;
				}
				adde(tmpa.y,tmpb.y,tmpa.val+tmpb.val);
				adde(tmpb.y,tmpa.y,tmpa.val+tmpb.val);
			}
		}
	}
	for(int i=1;i<=n;i++) {
		dijkstra(i,i);
	}
	while(tim--) {
		cin>>u>>v;
		ll res=INF;
		for(int p=0;p<(int)vec[u].size();p++) {
			Node tmpa=vec[u][p];
			for(int q=0;q<(int)vec[v].size();q++) {
				Node tmpb=vec[v][q];
				if(dis[tmpa.y][tmpb.y]>=INF) {
					continue;
				}
				
				ll tmp=a[u]+a[v]+dis[tmpa.y][tmpb.y]+tmpa.val+tmpb.val;
				res=min(res,tmp);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
