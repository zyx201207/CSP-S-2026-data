#include<bits/stdc++.h>
#define se second
#define fir first
#define debug(x) cerr<<#x<<':'<<(x)<<endl;
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=505,M=5e5+5;
const ll inf=1e18;
int c,m,n,d,q;
ll w[M],k[N];
vector<pii > bel[M];//每个点属于哪些线路 和地铁站去站台换乘的时间 
//vector<pii >a[N];//每个线路对应的地铁站和地铁站去站台换乘的时间 
ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",w+i);
	for(int i=1;i<=n;i++){
		scanf("%d",k+i);
		for(int j=1;j<=k[i];j++){
			int u,v;
			scanf("%d%d",&u,&v);
//			a[i].push_back({u,v});
			bel[u].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++){
		int sz=bel[i].size();
		for(int u=0;u<sz;u++){
			for(int v=u+1;v<sz;v++){
				ll val=bel[i][u].se+bel[i][v].se,
				n1=bel[i][u].fir,n2=bel[i][v].fir;
				dis[n1][n2]=dis[n2][n1]=
					min(dis[n1][n2],val);
			}
		}
	}
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--){
		int st,nd;
		scanf("%d%d",&st,&nd);
		ll ans=inf;
		for(int i=0;i<bel[st].size();i++){
			for(int j=0;j<bel[nd].size();j++){
				int u=bel[st][i].fir,v=bel[nd][j].fir;
				ll val=bel[st][i].se+bel[nd][j].se;
				ans=min(ans,dis[u][v]+val);
			}
		}
		printf("%lld\n",w[st]+ans+w[nd]);
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
