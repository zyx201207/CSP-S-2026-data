#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e6+5;
int c,T,n,K,st[N][25],dep[N],fa[N],rk[N];
vector<int> Adj[N];
bool ch[N];
ll ans = 2e18;
int findroot(int x){
	return (fa[x]==x?x:fa[x]=findroot(fa[x]));
}
void merge(int x,int y){
	int fx = findroot(x),fy = findroot(y);
	if(fx == fy)return;
	if(rk[fx] > rk[fy])fa[fy] = fx;
	else{
		if(rk[fx] == rk[fy])++rk[fy];
		fa[fx] = fy;
	}
}
int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);
	for(int j=21;j>=0;--j){
		if(dep[st[x][j]] >= dep[y])x = st[x][j];
	}
	if(x == y)return x;
	for(int j=21;j>=0;--j){
		if(st[x][j] != st[y][j])x = st[x][j],y = st[y][j];
	}
	return st[x][0];
}
ll get_dis(int x,int y){
	int lca = LCA(x,y);
	return (ll)dep[x]-dep[lca]+dep[y]-dep[lca];
}
void solve(){
	for(int i=1;i<=n;++i)fa[i] = i,rk[i] = 1;
	for(int i=1;i<=n;++i){
		if(ch[i]){
			int l = Adj[i].size();
			for(int j=0,v;j<l;++j){
				v = Adj[i][j];
				if(ch[v])merge(i,v);
			}
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;++i){
		if(ch[i] && findroot(i)==i)++cnt;
	}
	if(cnt > 2)return;
	//for(int i=1;i<=n;++i)cout<<ch[i]<<" ";
	//cout<<endl;
	ll mx = 0ll,sum;
	for(int i=1;i<=n;++i){
		if(ch[i])continue;
		sum = 2e18;
		for(int j=1;j<=n;++j){
			if(!ch[j])continue;
			//cout<<"&&"<<i<<" "<<j<<" "<<get_dis(i,j)<<endl;
			sum = min(sum,get_dis(i,j));
		}
		mx = max(mx,sum);
	}
	//cout<<mx<<endl;
	ans = min(ans,mx);
}
void dfs(int x,int cnt){
	if(x > n){
		if(cnt != K)return;
		solve();
		return;
	}
	if(n-x+1 < K-cnt)return;
	if(cnt < K){
		ch[x] = 1;
		dfs(x+1,cnt+1);
	}
	ch[x] = 0;
	dfs(x+1,cnt);
}
void dfs1(int u,int fa){
	int l = Adj[u].size();
	dep[u] = dep[fa]+1;
	st[u][0] = fa;
	for(int j=1;j<=21;++j)st[u][j] = st[st[u][j-1]][j-1];
	for(int i=0,v;i<l;++i){
		v = Adj[u][i];
		if(v == fa)continue;
		dfs1(v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&K); ans = 2e18;
		for(int i=1;i<=n;++i){
			Adj[i].clear(); dep[i] = 0;
			for(int j=0;j<=21;++j)st[i][j] = 0;
		}
		for(int i=1,u,v;i<n;++i){
			scanf("%d%d",&u,&v);
			Adj[u].push_back(v);
			Adj[v].push_back(u);
		}
		dfs1(1,0);
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
