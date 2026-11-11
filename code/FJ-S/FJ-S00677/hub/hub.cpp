#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int n,c,t,k;
bool vis[N];
int f[N][25],dep[N];
vector<int> r[N];
void dfs(int u,int fa){
	f[u][0]=fa;
	for(int i=0;i<r[u].size();++i){
		int v=r[u][i];
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}

int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=24;i>=0;--i){
		if(dep[f[u][i]]>=dep[v])u=f[u][i];
	}
	if(u==v)return u;
	for(int i=24;i>=0;--i){
		if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	}
	return f[u][0];
}

int a[N],b[N],ff[N];
int find(int x){
	if(ff[x]==x)return x;
	return ff[x]=find(ff[x]);
}
int ans;
void sol(){
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(vis[i]){
			a[++cnt]=i;b[i]=cnt;
		}
	}
	for(int i=1;i<=k;++i)ff[i]=i;
	for(int i=1;i<=k;++i){
		for(int j=0;j<r[a[i]].size();++j){
			int v=r[a[i]][j];
			if(vis[v]){
				ff[find(i)]=find(b[v]);
			}
		}
	} 
	set<int> s;
	for(int i=1;i<=k;++i){
		s.insert(ff[i]);
		if(s.size()>2)return;
	}
	int mx=0;
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		int mn=n+n;
		for(int j=1;j<=k;++j){
			int sum=dep[a[j]]+dep[i]-2*dep[lca(i,a[j])];
			mn=min(mn,sum);
		}
		mx=max(mx,mn);
	}
	ans=min(ans,mx);
}


void dfs1(int p,int cnt){
	if(cnt+n-p+1<k||cnt>k)return;
	if(p>n){
		if(cnt==k){
			sol();
		}
		return;
	}
	vis[p]=0;
	dfs1(p+1,cnt);
	vis[p]=1;
	dfs1(p+1,cnt+1);
	vis[p]=0;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)r[i].clear(),vis[i]=0;
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			r[u].push_back(v),r[v].push_back(u);
		}
		dep[1]=1;f[1][0]=0;
		dfs(1,0);
		for(int i=1;i<=24;++i){
			for(int j=1;j<=n;++j){
				f[j][i]=f[f[j][i-1]][i-1];
			}
		}
		ans=n+n;
		dfs1(1,0);
		cout<<ans<<'\n';
	}
	//15pts
	return 0;
} 
