#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,t[N],tt[N][30],dis[N],vis[N],com[N];
struct Edge{
	int v,w;
	operator<(const Edge& __y) const
      { return w > __y.w; }
};
priority_queue<Edge>p;
vector<Edge>e[N];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)dis[i]=0x3f3f3f3f;
	for(int i=1;i<=m;i++)cin >> t[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		int u,nv;
		for(int j=1;j<=k;j++){
			cin >> nv;
			cin >> tt[nv][i];
			if(u!=0){
				e[u].push_back({nv,i});
				e[nv].push_back({u,i});
			}
			u=nv;
		}
	}
	while(q--){
		for(int i=1;i<=m;i++){
			dis[i]=0x3f3f3f3f;
			com[i]=0;
			vis[i]=0;
		}
		int x,y;
		cin >> x >> y;
		dis[x]=0;
		p.push({x,dis[x]});
		while(!p.empty()){
			int u=p.top().v;
			p.pop();
			if(vis[u]!=0)continue;
			vis[u]=1;
			int len=e[u].size();
			for(int i=0;i<len;i++){
				int nv=e[u][i].v,ncom=e[u][i].w;
				if(vis[nv]!=0)continue;
				if(ncom!=com[u]&&com[u]!=0)dis[nv]=min(dis[nv],dis[u]+tt[u][com[u]]+tt[u][ncom]);
				else dis[nv]=min(dis[nv],dis[u]);
				if(com[u]==0)com[u]=ncom;
				com[nv]=ncom;
				//cout<<nv<<" "<<dis[nv]<<" "<<ncom<<"\n";
				p.push({nv,dis[nv]});
			}
		}
		cout<<dis[y]+t[x]+t[y]+tt[x][com[x]]+tt[y][com[y]]<<"\n";
	}
	return 0;
} 
