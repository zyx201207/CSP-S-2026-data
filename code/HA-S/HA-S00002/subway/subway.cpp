#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=501,M=5e5+5,W=N*N;
const ll inf = 0x3f3f3f3f3f3f3f3f;
typedef pair<ll,int> pii;
vector<pii> G[M];
int c,n,m,d,q,w[M];
ll dis[N][N];
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
signed main(){
	fre("subway");
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1,k,x,w;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>x>>w;
			G[x].push_back({i,w});
		}
	}
	memset(dis,inf,sizeof dis);
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i){
		for(int p1=0;p1<G[i].size();++p1){
			for(int p2=0;p2<G[i].size();++p2){
				pii x = G[i][p1],y=G[i][p2];
				int u = x.first,v=y.first,w1=x.second,w2=y.second;
				dis[u][v]=dis[v][u]=min(dis[u][v],1ll*w1+w2);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1,a,b;i<=q;++i){
		cin>>a>>b;ll ans=inf;
		for(int p1=0;p1<G[a].size();++p1){
			for(int p2=0;p2<G[b].size();++p2){
				pii x = G[a][p1],y=G[b][p2];
				int u = x.first,v=y.first,w1=x.second,w2=y.second;
				ans=min(ans,1ll*w[a]+w[b]+w1+w2+dis[u][v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
