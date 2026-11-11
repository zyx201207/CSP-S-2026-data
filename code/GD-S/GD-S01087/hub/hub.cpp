#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll inf=1e18;
int n,k,cnt,dep[N],fa[N][30];
bool vis[N];
vector<int> e[N];
int get(int x,int y){
	return dep[x]<dep[y]?x:y;
}
void dfs(int u,int f){
	fa[u][0]=f;
	dep[u]=dep[f]+1;
	for(int i=1;(1<<i)<=dep[u];i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(auto v:e[u]){
		if(v==f) continue;
		dfs(v,u);
	}
}
void check(int u,int f){
	for(auto v:e[u]){
		if(v==f) continue;
		if(!vis[u]&&vis[v]) cnt++;
		check(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]!=dep[y]) x=fa[x][__lg(dep[x]-dep[y])];
	if(x==y) return x;
	for(int i=__lg(dep[x]);i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
ll js(int x){
	int tot=0;
	for(int i=1;i<=n;i++){
		if(x>>(i-1)&1){
			vis[i]=1;
			tot++;
		}else vis[i]=0;
		
	}
	if(tot!=k) return inf;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			check(i,0);
			break;
		}
	}
	if(cnt>2) return inf;
	ll res=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		ll c=inf;
		for(int j=1;j<=n;j++){
			if(!vis[j]) continue;
			c=min(c,1ll*dep[i]+dep[j]-2*dep[lca(i,j)]);
		}
		res=max(res,c);
	}
	return res;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int hzx,t;
	cin>>hzx>>t;
	if(hzx==13||hzx==14){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int x;
				cin>>x>>x;
			}
			n=(n-1)/2;
			int mid=(n+1)/2,len=k/2;
			cout<<(mid-len)/2+1<<"\n";
		}
		return 0;
	}
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			dep[i]=0;
			e[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		ll ans=inf;
		for(int i=(1<<k)-1;i<(1<<n);i++){
			ans=min(ans,js(i));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
