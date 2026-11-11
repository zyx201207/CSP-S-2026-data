#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1003;
int C,T;
int n,k;
vector<int> G[N];
struct Edge{
	int u,v;
}edge[N];
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int a,int b){
	fa[find(a)]=find(b);
}
int dep[N];
int st[N][21];
void dfs(int u,int fa){
	st[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=1;i<=20;i++) st[u][i]=st[st[u][i-1]][i-1];
	for(auto v:G[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}
int get_lca(int aa,int bb){
	int a=aa,b=bb;
	if(dep[a]<dep[b]) swap(a,b);
	for(int i=20;i>=0;i--) if(dep[st[a][i]]>=dep[b]) a=st[a][i];
	if(a==b) return a;
	for(int i=20;i>=0;i--) if(st[a][i]!=st[b][i]) a=st[a][i],b=st[b][i];
	return st[a][0];
}
int dist(int a,int b){
//	cout<<"get_lca "<<a<<" "<<b<<" "<<get_lca(a,b)<<" dist "<<dep[a]+dep[b]-2*dep[get_lca(a,b)]<<"\n";
	return dep[a]+dep[b]-2*dep[get_lca(a,b)];
}
void solve(){
	for(int i=1;i<=n;i++) dep[i]=0;
	memset(st,0,sizeof st);
	cin>>n>>k;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++){
		cin>>edge[i].u>>edge[i].v;
		G[edge[i].u].push_back(edge[i].v);
		G[edge[i].v].push_back(edge[i].u);
	}
	dfs(1,0);
	int ans=1e16;
	for(int mask=0;mask<(1LL<<n);mask++){
		for(int i=1;i<=n;i++) fa[i]=i;
		int cnt=0;
		vector<int> have_use;
		for(int i=0;i<n;i++) if((1LL<<i)&mask) cnt++,have_use.push_back(i+1);
		if(cnt!=k) continue;
		for(int i=1;i<n;i++){
			if(((1LL<<(edge[i].u-1LL))&mask)==0) continue;
			if(((1LL<<(edge[i].v-1LL))&mask)==0) continue;
			merge(edge[i].u,edge[i].v);
		}
		cnt=0;
		for(int i=1;i<=n;i++) if(fa[i]==i and (1LL<<(i-1)&mask)) cnt++;
		if(cnt>=3) continue;
		int maxx=0;
		for(int i=0;i<(int)have_use.size();i++){
			for(int j=i+1;j<(int)have_use.size();j++){
				maxx=max(maxx,dist(have_use[i],have_use[j]));
			}
		}
		ans=min(ans,maxx);
	}
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>T;
	while(T--) solve();
	return 0;
} 
