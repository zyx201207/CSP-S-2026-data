#\
i\
n\
c\
l\
u\
d\
e\
 \
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
using namespace std;

const int LG=20,dtl=249249249;
struct line{int to,nxt;}r[2000000];
int c,T,n,k,cntt,ans,head[1000001],mx,f[1000001][LG+1],dp[1000001][2],mdp[1000001];
int dep[1000001],dfn[1000001],cntn,siz[1000001];
void add(int u,int v){r[++cntt]={v,head[u]};head[u]=cntt;}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=LG;i>=0;i--)if(dep[f[u][i]]>=dep[v])u=f[u][i];
	if(u==v)return u;
	for(int i=LG;i>=0;i--)if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	return f[u][0];
}
void dfs1(int u,int fr){
	mdp[u]=dep[u]=dep[fr]+1;
	f[u][0]=fr;siz[u]=1;dfn[u]=++cntn;
	for(int i=head[u];i;i=r[i].nxt){
		int v=r[i].to;
		if(v==fr)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		mdp[u]=max(mdp[u],mdp[v]);
	}
}
//void dfs2(int u,int fr){
//	for(int i=head[u];i;i=r[i].nxt){
//		int v=r[i].to;
//		if(v==fr)continue;
//		dfs2(v,u);
//	}
//}
int dis(int u,int v){
	int t=lca(u,v);
	return dep[u]+dep[v]-dep[t]*2;
}
//bool check(int MXL){mx=MXL;
////	for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=0;
////	dfs2(1,1);
////	for(int i=1;i<=n;i++){
////		for(int j=i+1;j<=n;j++){
////			if(dfn[j]>=dfn[i]&&dfn[j]<=dfn[i]+siz[i]-1)continue;
////			if(dis(i,j)>mx)continue;
////			for(int l=1;l<=n;l++){
////				
////			}
////		}
////	}
//}
bool vis[11];
int fa[1001];
int find(int a){if(fa[a]!=a)fa[a]=find(fa[a]);return fa[a];}
void comb(int a,int b){fa[find(a)]=find(b);}
void check(int cnt){
	for(int i=1;i<=n;i++)fa[i]=i;
	int nmx=0,comp=cnt;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			for(int j=head[i];j;j=r[j].nxt){
				int v=r[j].to;
				if(vis[v]&&find(i)!=find(v)){
					comp--;
					comb(i,v);
				}
			}
		}
	}
	if(comp>2)return;
	for(int i=1;i<=n;i++){
		int nmn=dtl;
		for(int j=1;j<=n;j++){
			if(vis[j])nmn=min(nmn,dis(i,j));
		}
		nmx=max(nmx,nmn);
	}
//	if(nmx<ans){
//		for(int i=1;i<=n;i++)cerr<<vis[i];cerr<<"\n";
//		for(int i=1;i<=n;i++){
//			int nmn=dtl;
//			for(int j=1;j<=n;j++){
//				if(vis[j]){
////					cerr<<"i:"<<i<<" j:"<<j<<" "<<dis(i,j)<<"\n";
//				}
//			}
//		}
//	}
	ans=min(ans,nmx);
}
void dfs(int dep,int cnt){
	if(cnt>k)return;
	if(dep>n){
		check(cnt);
		return;
	}
	dfs(dep+1,cnt);
	vis[dep]=true;
	dfs(dep+1,cnt+1);
	vis[dep]=false;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	cin>>c>>T;
	for(int iiii=1;iiii<=T;iiii++){
		cin>>n>>k;
		cntt=0;cntn=0;
		for(int i=1;i<=n;i++)head[i]=0;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			add(u,v),add(v,u);
		}
		ans=dtl;
		dfs1(1,0);
		for(int j=1;j<=LG;j++)for(int i=1;i<=n;i++)f[i][j]=f[f[i][j-1]][j-1];
		dfs(1,0);
//		int l=0,r=n,ans=n;
//		while(l<=r){
//			int mid=(l+r)/2;
//			if(check(mid)){
//				r=mid-1;
//				ans=mid;
//			}else l=mid+1;
//		}
		cout<<ans<<"\n";
	}
	akioi;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
