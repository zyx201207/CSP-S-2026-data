#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1|1)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pb push_back

inline int read(){
  char c=getchar();int d=0,f=0;
  while(!isdigit(c)){
	if(c=='-') f=1;c=getchar();
  }while(isdigit(c)){
	d=d*10+c-'0';c=getchar();
  }return f?-d:d;
}
const int N=1e6+100,INF=1e18;
vector<int> g[N];
int n,k;
int vis[N],cnt[N],mind[N],f[N];
void bf(int u,int fa){
	cnt[u]=vis[u];mind[u]=INF;f[u]=fa;
	//cnt连通块数量
	if(vis[u]){
		mind[u]=0;
		for(int v:g[u]){
			if(v==fa) continue;
			bf(v,u);
			if(!vis[v]) cnt[u]+=cnt[v];
		}
	}else{
		for(int v:g[u]){
			if(v==fa) continue;
			bf(v,u);
			cnt[u]+=cnt[v];
			mind[u]=min(mind[u],mind[v]+1);
		}
	}
}
void dfs(int u,int fa){
	f[u]=fa;
	for(int v:g[u]){
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
bool check(int mid){
	int pos=0,maxdep=0;
	for(int i=1;i<=n;i++){
		if(dep[i]>maxdep){
			pos=i;maxdep=dep[i];
		}
	}
	if(maxdep<=mid) return 1;
	int x=pos;
	for(int i=1;i<=mid;i++) x=f[x];
	
}
struct EDGE{
	int u,v;
}e[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		//多测清空 
		n=read();k=read();
		for(int i=1;i<=n;i++){
			g[i].clear();vis[i]=0;
		}
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			g[u].pb(v);g[v].pb(u);
			e[i]={u,v};
		}
		if(c<=3){
			int ans=INF;
			for(int s=0;s<(1<<n);s++){
				int tmp=0;
				for(int i=1;i<=n;i++){
					vis[i]=(s>>(i-1))&1;
					tmp+=vis[i];
				}
				if(tmp!=k) continue;
				bf(1,0);
				if(cnt[1]<=2) {
					int res=0;
					for(int i=1;i<=n;i++){
						int rec=mind[i];
						int x=i,cnt=0;
						while(x){
							rec=min(rec,mind[x]+cnt);
							x=f[x];cnt++;
						}
						res=max(res,rec);
					}
					ans=min(ans,res);
				}
			}
			printf("%lld\n",ans);
		}else if(k==2){
			dep[1]=0;
			dfs(1,0);
		}
	}

  return 0;
}
