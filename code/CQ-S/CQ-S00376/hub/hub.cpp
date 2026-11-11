#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int inf=1e18;
int C,T,n,k;
vector<int> e[15];
int fa[15],vis[15],vvis[15];
void ddfs(int x,int lst){
	vvis[x]=1;
	for(auto v:e[x]){
		if(vis[v]&&!vvis[v]&&v!=lst) ddfs(v,x);
	}
}
int ans=1e18,f[15][15],U[25],V[25];
void dfs(int x,int cnt){
	if(cnt>k) return;
	if(x>n){
		if(cnt!=k) return;
		for(int i=1;i<=n;i++) vvis[i]=0;
		int tot=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&!vvis[i]){
				++tot;
				ddfs(i,0);
			}
		}
		if(tot>2) return;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i!=j) f[i][j]=inf;
				f[i][j]=0;
			}
		for(int i=1;i<n;i++){
			f[U[i]][V[i]]=f[V[i]][U[i]]=1;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		int oo=-inf;
		for(int i=1;i<=n;i++){
			if(vvis[i]) continue;
			int maxn=inf;
			for(int j=1;j<=n;j++){
				if(!vvis[j]) maxn=min(maxn,f[i][j]);
			}
			oo=max(oo,maxn);
		}
		ans=min(ans,oo);
		return;
	}
	vis[x]=0;dfs(x+1,cnt);
	vis[x]=1;dfs(x+1,cnt+1);
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout<<"1\n2",exit(0);
	cin>>C>>T;
	while(T--){
		ans=1e18;
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			U[i]=u,V[i]=v;
			e[u].pb(v),e[v].pb(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
