#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define int long long
int ccc,n,m,d,q,wn[N],s[N][25],dis[N],dep[N],x,y;
int hd[N],to[N<<1],nxt[N<<1],w[N<<1],idx=1,f[N];
bool vis[N];
struct Z{
	int x,y,z;
}e[N];
bool cmp(Z x,Z y){
	return x.z<y.z;
}
int fd(int u){
	if(u==f[u]) return u;
	f[u]=fd(f[u]);
	return f[u];
}
void add(int x,int y,int z){
	to[idx]=y;
	nxt[idx]=hd[x];
	w[idx]=z;
	hd[x]=idx++;
}
void dfs(int u,int fa){
	s[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue;
		dis[v]=dis[u]+w[i];
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int p=19;p>=0;p--)
		if(dep[s[x][p]]>=dep[y]) x=s[x][p];
	if(x==y) return x;
	if(s[y][0]==s[x][0]) return s[x][0];
	for(int p=19;p>=0;p--){
		if(s[s[x][p]][0]!=s[s[y][p]][0])
			x=s[x][p],y=s[y][p];
		else{
			x=s[x][p];
			break;
		}
	}
	return s[x][0];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>ccc>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>wn[i];
	int cnt=0;
	for(int i=1,k;i<=m;i++){
		++n;
		cin>>k;
		for(int j=1,v,z;j<=k;j++){
			cin>>v>>z;
			e[++cnt].x=n,e[cnt].y=v,e[cnt].z=z;
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int x=e[i].x,y=e[i].y;
		int fx=fd(x),fy=fd(y);
		if(fx==fy) continue;
		f[fy]=fx;
		vis[i]=1;
	}
	for(int i=1;i<=cnt;i++){
		int x=e[i].x,y=e[i].y,z=e[i].z;
		if(vis[i]) add(x,y,z),add(y,x,z);
	}
	dfs(1,0);
	for(int i=2;i<=n;i++)
		for(int p=1;p<=19;p++) s[i][p]=s[s[i][p-1]][p-1];
	while(q--){
		cin>>x>>y;
		int l=lca(x,y);
		//cout<<x<<' '<<y<<' '<<l<<endl;
		cout<<wn[x]+wn[y]+dis[x]+dis[y]-2*dis[l]<<'\n';
	}
} 
