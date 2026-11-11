#include<bits/stdc++.h>
using namespace std;
#define int long long
struct bn{
	int v,w;
};
struct bnbn{
	int u,w;
	bool operator <(bnbn o) const{
		return w>o.w;
	}
};
int c,n,m,d,qu,a[500007],b[500007],t[500007],x,y,f[507];
vector<bn>g[500007],gg[507];
priority_queue<bnbn>q;
void nb(){
	for(int i=1;i<=n;i++)f[i]=1e17;
	for(int i=0;i<g[x].size();i++){
		f[g[x][i].v]=g[x][i].w;
		q.push({g[x][i].v,g[x][i].w});
	}
	while(!q.empty()){
		bnbn u=q.top();
		q.pop();
		if(u.w>f[u.u])continue;
		for(int i=0;i<gg[u.u].size();i++){
			int v=gg[u.u][i].v;
			int w=gg[u.u][i].w;
			if(u.w+w<f[v]){
				f[v]=u.w+w;
				q.push({v,f[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j]>>t[j];
			g[b[j]].push_back({i,t[j]});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size()-1;j++){
			for(int ij=1;ij<g[i].size();ij++){
				gg[g[i][j].v].push_back({g[i][ij].v,g[i][j].w+g[i][ij].w});
				gg[g[i][ij].v].push_back({g[i][j].v,g[i][j].w+g[i][ij].w});
			}
		}
	}
	while(qu--){
		cin>>x>>y;
		nb();
		int ans=1e17;
		for(int i=0;i<g[y].size();i++){
			ans=min(ans,f[g[y][i].v]+g[y][i].w);
		}
		cout<<ans+a[x]+a[y]<<endl;
	}
}
