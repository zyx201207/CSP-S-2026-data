#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAXM=5e5+5,MAXN=505,INF=1e18;
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数
int w[MAXM];//记得加口到口 
int k[MAXN];
struct node {
	int v,t;
};
vector<node> tin[MAXM];
int dis[MAXN][MAXN];

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(node x:tin[i]){
			int u=x.v,ut=x.t;
			for(node y:tin[i]){
				int v=y.v,vt=y.t;
				dis[u][v]=min(dis[u][v],ut+vt);
				dis[v][u]=min(dis[v][u],ut+vt);
//				cout<<dis[u][v]<<' '<<u<<' '<<v<<' '<<i<<' '<<ut<<' '<<vt<<'\n';
			}
		} 
	}
	for(int kk=1;kk<=n;kk++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				dis[u][v]=min(dis[u][v],dis[u][kk]+dis[kk][v]);
			}
		}
	}
}
signed main (){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			tin[a].push_back({i,t});
		}
	}
	init();
	for(int i=1;i<=q;i++){
		int f,t;
		cin>>f>>t;
		int minn=INF;
		for(node x:tin[f]){
			int u=x.v,ut=x.t;
			for(node y:tin[t]){
				int v=y.v,vt=y.t;
				minn=min(dis[u][v]+ut+vt,minn);
//				cout<<dis[u][v]<<' '<<u<<' '<<v<<' '<<i<<' '<<ut<<' '<<vt<<'\n';
			}
		}
		cout<<minn+w[f]+w[t]<<'\n';
	}
//	cout<<dis[2][2];
	return 0;
}
