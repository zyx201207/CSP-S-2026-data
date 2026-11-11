#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510;
const int INF = 1e18;
const int M = 5e5 + 1000;

struct edge{
	int to,ww;
};

int c,n,m,dd,q;
int w[M];
int d[N][N];

vector<edge> g[M];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>dd>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	
	for(int i = 1;i <= n;i++){
		int k,u;cin>>k;
		edge x;x.to = i;
		for(int j = 1;j <= k;j++){
			cin>>u>>x.ww;
			g[u].push_back(x);
		}
	}
	
	memset(d,0x3f,sizeof(d));
	
	for(int i = 1;i <= m;i++){
		for(auto ed1 : g[i]) for(auto ed2 : g[i]){
			int u = ed1.to,v = ed2.to;
			if(u == v) continue;
			d[u][v] = d[v][u] = min(ed1.ww + ed2.ww,d[u][v]);
		}
	}
	
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
		}
	}
	
	for(int i = 1;i <= n;i++) d[i][i] = 0;
	
	while(q--){
		int x,y,ans = INF;cin>>x>>y;
		for(auto u : g[x]) for(auto v : g[y]) ans = min(ans,u.ww+v.ww+d[u.to][v.to]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	
	return 0;
}
