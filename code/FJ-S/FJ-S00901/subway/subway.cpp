#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=505,MAXM=5e5+5;
#define ll long long
int c,n,m,d,q;
ll val[MAXM];
struct edge{
	int v;
	ll w;
};
vector <edge> e[MAXM];
ll dis[MAXN][MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) cin>>val[i];
	for (int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for (int j=1;j<=k;j++){
			ll v,w;
			scanf("%d %lld",&v,&w);
			e[v].push_back({i,w});
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (i==j) dis[i][j]=0;
			else dis[i][j]=1e18;
		}
	for (int u=1;u<=m;u++){
		int siz=e[u].size();
		for (int i=0;i<siz;i++){
			for (int j=i+1;j<siz;j++){
//				cout<<u<<" "<<e[u][i].v<<" -> +"<<e[u][i].w+e[u][j].w<<" ->"<<e[u][j].v<<endl;
				dis[e[u][i].v][e[u][j].v]=dis[e[u][j].v][e[u][i].v]=min(dis[e[u][i].v][e[u][j].v],e[u][i].w+e[u][j].w);
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while (q--){
		int x,y;
		scanf("%d %d",&x,&y);
		ll ans=2e18;
//		cout<<"x="<<x<<" y="<<y<<endl;
		for (int i=0;i<e[x].size();i++){
			for (int j=0;j<e[y].size();j++){
				int u=e[x][i].v,v=e[y][j].v;
//				cout<<u<<" "<<v<<" "<<dis[u][v]<<endl;
				ans=min(ans,dis[u][v]+e[x][i].w+e[y][j].w);
			}
		}
		printf("%lld\n",ans+val[x]+val[y]);
	}
	return 0;
}
// 26-10-31 16:51 100
