#include<bits/stdc++.h>
#define int lint
using namespace std;
using lint=long long;
using llint=__int128;
using ldouble=long double;
const int MAX_N=5e5+10,MAX_M=510,INF=1e18;
int w[MAX_N];
struct node3{
	int to,val;
};
int dis[MAX_M][MAX_M];
int head[MAX_N*20],nxt[MAX_N*20],edge_cnt=0;
node3 to[MAX_N*20];
void add_edge(int u,int v,int w){
	to[++edge_cnt]={v,w};
	nxt[edge_cnt]=head[u];
	head[u]=edge_cnt;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,m,n,d,q;
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		int cnt;
		cin>>cnt;
		for(int j=1;j<=cnt;j++){
			int pos,t;
			cin>>pos>>t;
			add_edge(pos,i,t);
		}
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++) dis[i][j]=INF;
	}
	for(int i=1;i<=m;i++) dis[i][i]=0;
	for(int u=1;u<=n;u++){
		for(int i=head[u];i;i=nxt[i]){
			for(int j=head[u];j;j=nxt[j]){
				node3 x=to[i],y=to[j];
				int x_to=x.to,y_to=y.to,x_val=x.val,y_val=y.val; 
				if(x_to==y_to) continue;
				dis[x_to][y_to]=min(dis[x_to][y_to],x_val+y_val);
				dis[y_to][x_to]=min(dis[y_to][x_to],x_val+y_val);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int u=1;u<=m;u++){
			for(int v=1;v<=m;v++){
				if(dis[u][k]<INF&&dis[k][v]<INF){
					dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
					dis[v][u]=dis[u][v];
				}	
			}
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		int res=INF;
		for(int i=head[st];i;i=nxt[i]){
			for(int j=head[ed];j;j=nxt[j]){
				int x=to[i].to,y=to[j].to;
				if(dis[x][y]<INF) res=min(res,dis[x][y]+to[i].val+to[j].val);
			}
		}
		cout<<res+w[st]+w[ed]<<"\n";
	}
	return 0;
}
