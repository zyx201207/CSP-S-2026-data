#include <bits/stdc++.h>
using namespace std;
const int N=5e2+10;
const int M=5e5+10;
const int Q=1e5+10;
const long long INF=1e18;
int c,n,m,d,q,u,v,k[N];
long long ans,dis[N][N],w[M];
struct edge{
	int v;
	long long w;
	int nx;
}e[M*20];
int cnt,head[M];
void addEdge(int u,int v,long long w){
	e[++cnt]={v,w,head[u]};
	head[u]=cnt;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=INF;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a;
			long long t;
			cin>>a>>t;
			addEdge(a,i,t);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=head[i];j;j=e[j].nx){
			for(int k=head[i];k;k=e[k].nx){
				u=e[j].v;
				v=e[k].v;
				dis[u][v]=min(dis[u][v],e[j].w+e[k].w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		cin>>u>>v;
		ans=INF;
		for(int i=head[u];i;i=e[i].nx){
			for(int j=head[v];j;j=e[j].nx){
				int x=e[i].v;
				int y=e[j].v;
				ans=min(ans,dis[x][y]+e[i].w+e[j].w);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
//每条线路站台<=500:建立以站台为节点的图 
