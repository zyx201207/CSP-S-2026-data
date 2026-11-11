#include<bits/stdc++.h>
using namespace std;
const int maxn = 500+10;
int vis[maxn];
int c,n,m,d,q;
int w[maxn];
struct edge{
	int u,w;
};
vector<edge>v[maxn][maxn];
void dfs(int u){
	for(auto i:v[u]){
		if(i.u == u||vis[u])continue;
		vis[u] = 1;
		dfs(i.u);
		vis[u] = 0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		for(int j = 1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[a][0].push_back({i,t});
			v[a][i].push_back({0,t});
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
	}
}
