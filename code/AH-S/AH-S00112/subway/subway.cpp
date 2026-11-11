#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w;
};
long long w[500100];
vector<node> g[500100];
long long x,y;
long long a[110],t[110];
bool vis[500100];
long long ans;
void dfs(long long u,long long cnt){
	if(u==y){
		ans=min(ans,cnt);
		return;
	}
	vis[u]=1;
	long long l=g[u].size();
	for(int i=1;i<=l;i++){
		int v=g[u][i].v;
		if(vis[v]==0){
			dfs(v,cnt+g[u][i].w);
		}
	}
	vis[u]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	long long c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				g[a[j]].push_back({a[l],t[j]+t[l]});
				g[a[l]].push_back({a[j],t[j]+t[l]});
			}
		}
	}
	for(int i=1;i<=p;i++){
		ans=2e9;
		cin>>x>>y;
		dfs(x,0);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
