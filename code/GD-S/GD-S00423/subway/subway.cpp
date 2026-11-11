#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pir;
const int MAXN=5e5+505,mod=998244353,inf=0x3f3f3f3f;
int n,m,testid,D,q;
ll aw[MAXN];
struct edge{
	int u,v;
	ll w;
	bool operator<(const edge &o) const{
		return w<o.w;
	}
};
vector<edge> ed;
struct EDGE{
	int to,next;
	ll w;
}e[MAXN<<1];
int ecnt=0,head[MAXN];
inline void addedge(int u,int v,ll w){
	e[++ecnt]={v,head[u],w};
	head[u]=ecnt;
}
int f[MAXN],siz[MAXN];
inline int findf(int x){
	return f[x]==x?x:f[x]=findf(f[x]);
}
inline bool merge(int x,int y){
	x=findf(x),y=findf(y);
	if(x==y)
		return false;
	if(siz[x]>siz[y])
		swap(x,y);
	f[x]=y;
	siz[y]+=siz[x];
	return true;
}
void kru(){
	for(int i=1;i<=n+m;i++)
		f[i]=i,siz[i]=1;
	sort(ed.begin(),ed.end());
	for(auto i:ed){
		if(!merge(i.u,i.v))
			continue;
		addedge(i.u,i.v,i.w);
		addedge(i.v,i.u,i.w);
	}
}
int dp[MAXN],p[MAXN][21];
ll d[MAXN];
void dfs(int now,int fa){
	p[now][0]=fa;
	dp[now]=dp[fa]+1;
	for(int i=1;(1<<i)<dp[now];i++)
		p[now][i]=p[p[now][i-1]][i-1];
	for(int i=head[now];i;i=e[i].next){
		int toi=e[i].to;
		if(toi==fa)
			continue;
		d[toi]=d[now]+e[i].w;
		dfs(toi,now);
	}
}
inline int LCA(int x,int y){
	if(dp[x]<dp[y])
		swap(x,y);
	for(int i=0,t=dp[x]-dp[y];t;t>>=1,i++)
		if(t&1)
			x=p[x][i];
	if(x==y)
		return x;
	for(int i=20;i>=0;i--)
		if(p[x][i]^p[y][i])
			x=p[x][i],y=p[y][i];
	return p[x][0];
}
inline ll dis(int x,int y){
	return d[x]+d[y]-(d[LCA(x,y)]<<1);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>testid>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)
		cin>>aw[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		ll t;
		int a;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			ed.push_back({i+m,a,t});
		}
	}
	kru();
	dfs(1,1);
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		cout<<aw[x]+aw[y]+dis(x,y)<<"\n";
	}
	return 0;
}

