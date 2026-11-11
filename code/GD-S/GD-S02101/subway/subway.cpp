#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=510,M=5e5+10,mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
/*

*/
int C,T=1;
vector<pii> G[M];
int k[M],w[M],n,m,d,q; ll dis[N][N];
void mian(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,tt;cin>>u>>tt;
			G[u].push_back({i,tt});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=1e15;
#define foe(u,v,w,i) for(int i=0,v,w;i<(int)G[u].size()&&(v=G[u][i].x,w=G[u][i].y);i++)
	for(int i=1;i<=m;i++) foe(i,u,tu,_) foe(i,v,tv,__)
		dis[u][v]=min(dis[u][v],(ll)tu+tv);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int p,q; ll res=1e15; cin>>p>>q;
		foe(p,u,tu,_) foe(q,v,tv,__)
			res=min(res,dis[u][v]+tu+tv);
		cout<<res+w[p]+w[q]<<"\n";
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>C; while(T--) mian();
	return 0;
}

