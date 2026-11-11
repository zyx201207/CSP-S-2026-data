#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int P=505,N=5e5+5;
const ll inf=1e15;
int C,n,m,d,q,w[N],deg[N];
ll dis[P][P];
struct edge{
	int id,t;
	inline edge():id(0),t(0){}
	inline edge(int x,int y):id(x),t(y){}
}E[N][20];
inline void ckmin(ll &x,ll y){x=x<y?x:y;}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,u,t;i<=n;i++){
		cin>>k;while(k--) cin>>u>>t,E[u][deg[u]++]=edge(i,t);
		for(int j=1;j<=n;j++) dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<deg[i];j++){
			int u=E[i][j].id,t=E[i][j].t;
			for(int k=0;k<deg[i];k++) ckmin(dis[u][E[i][k].id],t+E[i][k].t);
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		ckmin(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=inf;
		for(int i=0;i<deg[x];i++) for(int j=0;j<deg[y];j++)
			ans=min(ans,(ll)E[x][i].t+dis[E[x][i].id][E[y][j].id]+E[y][j].t);
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
/*
题意说明：
1.口 <->(w) 厅 <->(t) 台
2.每条路线中途不用换台，即只有初末的t需要计入

感觉大样例有点水呀，最好打个对拍 
*/
