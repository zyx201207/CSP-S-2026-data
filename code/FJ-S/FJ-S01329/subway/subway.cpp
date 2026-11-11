#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[605][605],top,vis[605],t[605];
struct pw{
	ll v,wa;
};
vector<pw> g[605];
void dfs(ll now,ll u){
	if(vis[u]) return;
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		w[now][g[u][i].v]=min(w[now][u]+g[u][i].wa,w[now][g[u][i].v]);
		dfs(now,g[u][i].v);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=600;i++) for(int j=1;j<=600;j++) w[i][j]=1e18;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++){
		ll p;
		cin>>p;
		for(int j=1;j<=p;j++){
			ll v,w;
			cin>>v>>w;
			g[i+400].push_back({v,w});
			g[v].push_back({i+400,w});
		}
	}
	for(int i=1;i<=m;i++){
		w[i][i]=0;
		dfs(i,i);
		for(int j=1;j<=600;j++) vis[j]=0;
	}
	for(int i=1;i<=q;i++){
		ll l,r;
		cin>>l>>r;
		cout<<w[l][r]+t[l]+t[r]<<endl;
	}
	return 0;
}