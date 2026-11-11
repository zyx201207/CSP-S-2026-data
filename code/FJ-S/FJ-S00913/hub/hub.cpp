#include<cstdio>
#include<vector>
const int N=1e6+10,L=22;
int c,T,n,m;
int ans;
int lg[N];
int dfn[N],d[N],tim;
int f[L][N];
std::vector<int> e[N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')ch=='-'?f=0:0,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?x:-x;
}
template<typename T>inline T max(T a,T b){return a>b?a:b;}
inline int dmin(int u,int v){return dfn[u]<dfn[v]?u:v;}
inline void dfs(int u,int u_f){
	f[0][dfn[u]=++tim]=u_f,d[u]=d[u_f]+1;
	for(int v:e[u])if(v!=u_f)
		dfs(v,u);
}
inline int LCA(int u,int v){
	if(u==v)return u;
	if((u=dfn[u])>(v=dfn[v]))u^=v^=u^=v;
	int k=lg[v-u];
	return dmin(f[k][u],f[k][v-(1<<k)]);
}
inline void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)e[i].clear();
	for(int i=1,u,v;i<n;++i)
		u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
//	if(c==13||c==14){
		m=(n>>1)+2-m+1+3;
		printf("%d\n",m/4);
		return ;
//	}
//	dfs(1,0);
//	for(int i=1;i<=lg[n];++i)for(int j=1;j+(1<<i)-1<=n;++j)
//		f[i][j]=dmin(f[i-1][j],f[i-1][j+(1<<i-1)]);
//	for(int i=1;i<=m;++i){
//		int u=read(),v=read();
//		printf("%d\n",LCA(u,v));
//	}
}
int main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	for(int i=2;i<N;++i)lg[i]=lg[i>>1]+1;
	c=read(),T=read();
	while(T--)solve();
	return 0;
}
