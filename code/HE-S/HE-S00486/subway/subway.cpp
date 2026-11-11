#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y,ans,w[1005],vis[1005],a,t;
vector<pair<int,int>> e[1005];
void dfs(int u,int s){
	if(u==y){
		ans=min(ans,s+w[u]);
		return;
	}
	pair<int,int> vt;
	for(auto vt:e[u]){
		int v=vt.first,t=vt.second;
		if(!vis[v]){
			vis[v]=1;
			dfs(v,s+t);
			vis[v]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		cin >> x >> y;
		if(k==2){
			cin >> a >> t;
			e[x].push_back({a,t});
			e[a].push_back({x,y});
		}
	}
	for(int i=1;i<=q;i++){
		ans=0x3f3f3f3f;
		cin >> x >> y;
		dfs(x,w[x]);
		cout << ans << '\n';
	}
	return 0;
}
