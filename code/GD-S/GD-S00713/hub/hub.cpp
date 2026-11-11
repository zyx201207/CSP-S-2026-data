#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
const int N=1e6+10,L=20;
int n,k,fa[N],f[N][L+3],dep[N];
vector<int>e[N];
bool vis[N];
inline void dfs2(int x,int fa){
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int j=1;j<=L;j++)f[x][j]=f[f[x][j-1]][j-1];
	for(int to:e[x]){
		if(to==fa)continue;
		dfs2(to,x);
	} 
}
inline int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=L;i>=0;i--){
		if(dep[f[u][i]]>=dep[v]){
			u=f[u][i];
		}
	}
	if(u==v)return u;
	for(int i=L;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
} 
inline int find(int x){
	if(fa[x]!=x)return fa[x]=find(fa[x]);
	return x;
}
inline void merge(int u,int v){
	int x=find(u),y=find(v);
	if(x==y){
		return;
	}
	fa[y]=x;
}
void dfs(int x,int fa){
	for(int to:e[x]){
		if(to==fa)continue;
		if(vis[to]&&vis[x]){
			merge(to,x); 
		}
		dfs(to,x);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios;
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs2(1,0); 
		if(c<=3){
			int all=(1<<n);
			int ans=inf;
			for(int mask=0;mask<all;mask++){
				int cnt=0;
				for(int i=1;i<=n;i++){
					fa[i]=i;
					if((mask>>(i-1))&1){
						vis[i]=1;
						cnt++;
					}else{
						vis[i]=0;
					}
				}
				if(cnt!=k)continue;
				dfs(1,0);
				cnt=0;
				for(int i=1;i<=n;i++){
					if(i!=find(i)||!vis[i])continue;
					cnt++;
				}
				if(cnt>2)continue;
				int res=0;
				for(int i=1;i<=n;i++){
					int res2=inf;
					for(int j=1;j<=n;j++){
						if(!vis[j])continue;
						res2=min(res2,dep[i]+dep[j]-2*dep[lca(i,j)]);
					}
					if(res2==inf)continue;
					res=max(res,res2);
				}
				ans=min(ans,res);
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}

