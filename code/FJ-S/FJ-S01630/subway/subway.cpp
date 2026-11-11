#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+10,N=505;
const int INF=1e17;
int c,n,m,d,q,w[M];
struct Edge{
	int to,w;
	Edge(){}
	Edge(int t,int ww):to(t),w(ww){}
};
vector<Edge>e[N+M];
//vector<Edge>two[N];
int G[N][N],dis[N][N];
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(G[i][j] || i==j) dis[i][j]=G[i][j];
			else dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int k=1;k<=n;k++){
				if(k==i || j==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,w;cin>>x>>w;
			e[i+m].push_back(Edge(x,w));
			e[x].push_back(Edge(i+m,w));
		}
	}
	for(int i=1;i<=m;i++){
		if(e[i].size()==1) continue;
		for(int j=0;j<e[i].size();j++){
			for(int k=j+1;k<e[i].size();k++){
				int u=e[i][j].to-m,uw=e[i][j].w;
				int v=e[i][k].to-m,vw=e[i][k].w;
				if(G[u][v]==0) G[u][v]=G[v][u]=uw+vw;
				else G[u][v]=G[v][u]=min(G[u][v],uw+vw);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<G[i][j]<<" ";
//		cout<<endl;
//	}
	floyd();
	while(q--){
		int x,y,ans=INF;cin>>x>>y;
		for(int i=0;i<e[x].size();i++){
			for(int j=0;j<e[y].size();j++){
				ans=min(ans,dis[e[x][i].to-m][e[y][j].to-m]+e[x][i].w+e[y][j].w);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
