#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e6+5,M=1e2+5,LOG=20;
const int INF=0x3f3f3f3f,MOD=1e9+7;
typedef long long LL;
int c,t,n,k,x,y,dep[N],fa[N],f[N][LOG];
bool vis[N];
vector<int>g[N];
void dfs(int u,int faa){
	dep[u] = dep[faa]+1;
	fa[u] = faa;
	for(auto v:g[u]){
		if(v==faa)continue;
		dfs(v,u);
	}
}
void lcadfs(int u,int faa){
	f[u][0] = faa;
	for(int i=1;i<LOG;i++)
		f[u][i] = f[f[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v==faa)continue;
		lcadfs(v,u);
	}
}
void mark(int u,int faa){
	vis[u] = 1;
	for(auto v:g[u]){
		if(v==faa)continue;
		mark(v,u);
	} 
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=LOG-1;i>=0;i--)
		if(dep[f[u][i]]>=dep[v])
			u = f[u][i];
	if(u==v)return u;
	for(int i=LOG-1;i>=0;i--)
		if(f[u][i]!=f[v][i])
			u = f[u][i],v = f[v][i];
	return f[u][0];
}
int len(int u,int v){
	return dep[u]+dep[v]-dep[lca(u,v)]*2;
}
bool check(int mid){
	memset(dep,0,sizeof dep);
	memset(fa,0,sizeof fa); 
	dfs(1,0);
	int maxi=0,maxx=0;
	for(int i=1;i<=n;i++)
		if(dep[i]>maxx)
			maxx = dep[i],maxi = i;
	for(int i=1;i<=mid;i++)
		maxi = fa[maxi];
	for(int i=1;i<=n;i++)
		cout<<dep[i]<<" ";
	cout<<endl<<mid<<" "<<maxi<<" "<<maxx<<endl;
	mark(maxi,fa[maxi]);
	memset(dep,0,sizeof dep);
	memset(fa,0,sizeof fa);
	memset(f,0,sizeof f);
	dfs(maxi,0);
	lcadfs(maxi,0);
	maxx = 0;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&dep[i]>maxx)
			maxx = dep[i],maxi = i;
	mark(maxi,fa[maxi]);
	int res=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			res = max(res,min(len(i,maxi),dep[i])-mid);
	return res<=k;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int l=0,r=n,ans;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))r = mid-1,ans = mid;
			else l = mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
 
