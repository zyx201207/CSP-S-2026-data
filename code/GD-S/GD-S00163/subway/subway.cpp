#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using pli = pair<LL,int>;
const int N = 5e5+505;
int c,n,m,d,q,w[N];
struct edge{
	int v;
	LL w;
};
vector<edge> g[N],vt[N];
LL dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j] = 2e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j = 0;j<g[i].size();j++){
			for(int k = 0;k<g[i].size();k++){
				if(j==k) continue;
				int u = g[i][j].v,v = g[i][k].v;
				dis[u-m][v-m] = min(dis[u-m][v-m],g[i][j].w+g[i][k].w);
				//vt[u].push_back({v,g[i][j].w+g[i][k].w});
				//vt[v].push_back({u,g[i][j].w+g[i][k].w});
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j] = min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		LL ans = 2e18;
		for(auto &i:g[x]){
			for(auto &j:g[y]){
				ans = min(ans,w[x]+w[y]+i.w+j.w+dis[i.v-m][j.v-m]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
