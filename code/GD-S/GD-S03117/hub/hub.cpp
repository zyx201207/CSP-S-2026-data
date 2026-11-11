#include<bits/stdc++.h>
#define rd read()
#define int long long
using namespace std;
inline int read(){
	int x=0,s=1,ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')s=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return s*x;
}
const int N=1000005,inf=1e9;
int n,k,rt,cnt,d[N],p[N],f[N],dfn[N],sz[N],pr[N],dis[11][11];bool vis[N];
mt19937 rnd(time(0));
vector<int> v[N],K;
inline void dfs(int x,int fa){
	d[x]=d[fa]+1,f[x]=fa,dfn[x]=++cnt;
	for(int i:v[x])if(i!=fa)dfs(i,x);
}
inline void clr(int x,int fa,int d){
	vis[x]=1;if(!d)return;
	for(int i:v[x])if(i!=fa)clr(i,x,d-1);
}
inline bool cmp(int x,int y){return d[x]>d[y];}
inline bool chk(int x){
	int mn=n;K={};
	for(int i=1;i<=n;++i)vis[i]=0;
	for(int i=1,q;i<=n;++i)if(!vis[p[i]]){
		int q=x,o=p[i],lst=0;while(o!=rt&&q-->0)lst=o,o=f[o];
		while(q-->0){
			if(v[o].size()==1)break;int j=rnd()%v[o].size();
			while(v[o][j]==lst)j=rnd()%v[o].size();
			lst=o,o=v[o][j];
		}
		clr(o,0,x),K.push_back(o);
	}
	for(int i=1;i<=n;++i)sz[i]=0;
	for(int i=0;i<K.size();++i){
		int u=K[i];while(u)++sz[u],u=f[u];
		int h=1;for(int j=1;j<=n;++j)if(sz[j]>0&&sz[j]<=i)++h;
		pr[i]=h;
	}
	for(int i=1;i<=n;++i)sz[i]=0;
	for(int z=1,i=K.size()-1;~i;--i,++z){
		int u=K[i];while(u)++sz[u],u=f[u];
		int h=1;for(int j=1;j<=n;++j)if(sz[j]>0&&sz[j]<z)++h;
		mn=min(mn,pr[i-1]+h);
	}
	return mn<=k;
}
struct DSU{
	int fa[N];
	inline void init(){for(int i=1;i<=n;++i)fa[i]=i;}
	inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	inline void merge(int x,int y){fa[find(x)]=find(y);}
}T;
inline void sol(){
	n=rd,k=rd,cnt=0;
	for(int i=1;i<=n;++i)v[i]={},p[i]=i;
	for(int i=1,x,y;i<n;++i)
		x=rd,y=rd,v[x].push_back(y),v[y].push_back(x);
	if(n<=10){
		memset(dis,0x3f,sizeof dis);int ans=n;
		for(int i=1;i<=n;++i)
			for(int j:v[i])dis[i][j]=dis[j][i]=1;
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		for(int s=0;s<1<<n;++s){
			if(__builtin_popcount(s)!=k)continue;vector<int> p,o;
			for(int t=1;t<=n;++t)if(s>>(t-1)&1)p.push_back(t);else o.push_back(t);
			T.init();for(int i:p)for(int j:p)if(dis[i][j]==1)T.merge(i,j);
			set<int> S;for(int i:p)S.insert(T.find(i));
			if(S.size()>2)continue;
			int r=0;
			for(int j:o){
				int mn=INT_MAX;
				for(int i:p)mn=min(mn,dis[i][j]);
				r=max(r,mn);
			}
			ans=min(ans,r);
		}
		cout<<ans<<'\n';return;
	}
	for(int i=1;i<=n;++i)if(v[i].size()>1){rt=i;break;}
	dfs(rt,0),sort(p+1,p+n+1,cmp);
	int l=1,r=n,M,res=0;
	while(l<=r)M=l+r>>1,chk(M)?res=M,r=M-1:l=M+1;
	cout<<res<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	int c=rd,T=rd;while(T--)sol();return 0;}
