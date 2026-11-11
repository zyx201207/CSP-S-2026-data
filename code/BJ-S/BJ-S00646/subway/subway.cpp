#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
const int INF = 1e18;
int c,n,m,d,q,dis[505][505],w[N],ans;
struct edges{
	int to,val;
};
vector<edges> g[N+505];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;++i)cin>>w[i];
	int u,v,js;
	for(int i = 1;i<=n;++i){
		cin>>js;
		for(int j = 1;j<=js;++j){
			cin>>u>>v;
			g[u].push_back({m+i,v}),g[m+i].push_back({u,v});
		}
	}
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j)dis[i][j]=INF;
		dis[i][i]=0;
	}
	edges f1,f2;
	for(int i = 1;i<=m;++i){
		for(int j = 0;j<(int)g[i].size();++j){
			for(int k = j+1;k<(int)g[i].size();++k){
				f1=g[i][j],f2=g[i][k];
				if(dis[f1.to-m][f2.to-m]>f1.val+f2.val){
					dis[f1.to-m][f2.to-m]=dis[f2.to-m][f1.to-m]=f1.val+f2.val;
				}
			}
		}
	}
	for(int k = 1;k<=n;++k){
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		cin>>u>>v;
		ans=INF;
		for(int i = 0;i<(int)g[u].size();++i){
			for(int j = 0;j<(int)g[v].size();++j){
				f1=g[u][i],f2=g[v][j];
				ans=min(ans,f1.val+f2.val+dis[f1.to-m][f2.to-m]);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
    return 0;
}
