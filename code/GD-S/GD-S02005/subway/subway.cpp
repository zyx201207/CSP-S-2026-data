#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int g[509][509];
int o[500009];
struct node{
	int id,t;
};
vector<node> p[500009];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;++i){
		cin>>o[i];
	}
	for(int i = 1;i<=n;++i){
		int _;
		cin>>_;
		for(int j = 1;j<=_;++j){
			int aij,tij;
			cin>>aij>>tij;
			p[aij].push_back({i,tij});
		}
	}
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			g[i][j] = g[j][i] = 1e18;
		}
	}
	for(int i = 1;i<=n;++i){
		g[i][i] = 0;
	}
	for(int i = 1;i<=m;++i){
		for(int j = 0;j<p[i].size();++j){
			for(int k = j+1;k<p[i].size();++k){
				int u = p[i][j].id,v = p[i][k].id,w = p[i][j].t+p[i][k].t;
				g[u][v] = min(g[u][v],w);
				g[v][u] = min(g[v][u],w);
			}
		}
	}
	for(int k = 1;k<=n;++k){
		for(int i = 1;i<=n;++i){
			for(int j = i+1;j<=n;++j){
				if(k == i||k == j||i == j) continue;
				g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
				g[j][i] = min(g[j][i],g[j][k]+g[k][i]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int mn = 1e18;
		for(auto I:p[x]){
			for(auto J:p[y]){
				int u = I.id,v = J.id;
				mn = min(mn,g[u][v]+I.t+J.t);
			}
		}
		cout<<mn+o[x]+o[y]<<'\n';
	}
}
