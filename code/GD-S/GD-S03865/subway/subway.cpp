#include<bits/stdc++.h>
using namespace std;
const int N=505,M=20010;
long long c,n,m,d,q,dis[N],t[N][M],a[N][M],l,r,ans;
bool vis[N];
struct Edge{int v,id;};
vector<Edge>g[M];
void dfs(int u,int fa,int idx,long long sum){
	if(u==r){
		ans=min(ans,sum);
		return;
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].v,id=g[u][i].id;
		if(v==fa) continue;
		if(vis[id]) continue;
		if(id==idx) dfs(v,u,id,sum-t[idx][u]+t[id][v]);
		else{
			vis[idx]=true;
			dfs(v,u,id,sum+t[id][u]+t[id][v]);
			vis[idx]=false;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>dis[i];
	for(int i=1;i<=n;i++){
		int k,v,w;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			if(j>=2){
				g[a[i][j-1]].push_back({a[i][j],i});
				g[a[i][j]].push_back({a[i][j-1],i});
			}
		}
	}
	while(q--){
		cin>>l>>r;
		ans=1e18;
		dfs(l,0,0,0);
		cout<<ans+dis[l]+dis[r]<<'\n';
	}
	return 0;
}
