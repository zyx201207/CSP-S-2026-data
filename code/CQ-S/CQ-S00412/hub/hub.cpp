#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
int c, t, n, k, ch[maxn], dep[maxn], dfn[maxn], fa[maxn], son[maxn];
int siz[maxn], top[maxn], xid, cnt, lbb[maxn<<1], f[maxn], bj[maxn];
int d[maxn], ans;
pair<int,int> jl[maxn];
struct nn{
	int to, nxt;
}gra[maxn<<1];
void add(int u, int v){
	gra[++cnt]={v,lbb[u]};
	lbb[u]=cnt;
}
void dfs1(int x){
	siz[x]=1;
	son[x]=-1;
	for(int i=lbb[x];i;i=gra[i].nxt){
		int v=gra[i].to;
		if(dep[v]) continue;
		dep[v]=dep[x]+1;
		fa[v]=x;
		dfs1(v);
		siz[x]+=siz[v];
		if(son[x]==-1||siz[v]>siz[son[x]]){
			son[x]=v;
		}
	}
}
void dfs2(int x, int tp){
	top[x]=tp;
	dfn[x]=++xid;
	if(son[x]==-1) return;
	dfs2(son[x],tp);
	for(int i=lbb[x];i;i=gra[i].nxt){
		int v=gra[i].to;
		if(v==fa[x]||v==son[x]) continue;
		dfs2(v,v);
	}
}
int gf(int x){
	if(x==f[x]) return x;
	else return f[x]=gf(f[x]);
}
void hb(int x, int y){
	int a=gf(x);
	int b=gf(y);
	f[x]=y;
}
int LCA(int x, int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]){
			swap(x,y);
		}
		x=fa[x];
	}
	return (dep[x]<dep[y])?x:y;
}
int dis(int x, int y){
	return dep[x]+dep[y]-(dep[LCA(x,y)]<<1);
}
void dfs(int x, int now){
	if(now>k) return;
	if(x==n+1){
		if(now<k) return;
		for(int i=1;i<=n;i++){
			if(ch[i])
			f[i]=i;
			bj[i]=0;
			d[i]=1e18;
		}
		for(int i=1;i<=n-1;i++){
			if(ch[jl[i].first]&&ch[jl[i].second]){
				hb(jl[i].first,jl[i].second);
			}
		}
		for(int i=1;i<=n;i++){
			bj[gf(i)]=1;
		}
		int s=0, re=0;
		if(s>1){
			return;
		}
		for(int i=1;i<=n;i++){
			if(ch[i]==0){
				for(int j=1;j<=n;j++){
					if(ch[j]){
						d[i]=min(d[i],dis(i,j));
					}
				}
				re=max(re,d[i]);
			}
		}
		ans=min(ans,re);
		return;
	}
	ch[x]=1;
	dfs(x+1,now+1);
	ch[x]=0;
	dfs(x+1,now);
}
void solve(){
	cin>>n>>k;
	int x, y;
	for(int i=1;i<=n<<1;i++){
		gra[i]={0,0};
		lbb[i]=0;
	}
	cnt=0;
	for(int i=1;i<=n-1;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
		jl[i]={x,y};
	}
	dep[1]=1;
	dfs1(1);
	dfs2(1,1);
	ans=1e18;
	dfs(1,0);
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
T:O(n)
M:
*/
