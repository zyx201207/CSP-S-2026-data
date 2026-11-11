#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+5,INF=0x3f3f3f3f3f3f3f3f;
int c,Case,n,k,head[MAXN],cnt=1;
struct edge{
	int next,to;
}e[MAXN*2];
inline void addedge(int u,int v){
	e[++cnt]=(edge){head[u],v};
	head[u]=cnt;
}
inline int popc(int n){
	return __builtin_popcount(n);
}
bool s[MAXN],vis[MAXN];
int minn[MAXN];
inline void dfs1(int u){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(vis[v]||!s[v])continue;
		dfs1(v);
	}
}
inline void dfs2(int u,int fa){
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa)continue;
		minn[v]=min(minn[v],minn[u]+1);
		dfs2(v,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>Case;
	while(Case--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			addedge(u,v),addedge(v,u);
		}
		int ans=INF;
		for(int sta=1;sta<(1<<n);sta++){
			if(popc(sta)!=k)continue;
			for(int id=1,S=1;id<=n;id++,S<<=1){
				if(sta&S)s[id]=1;
				else s[id]=0;
				vis[id]=0,minn[id]=INF;
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(s[i]&&(!vis[i]))dfs1(i),cnt++;
			}
			if(cnt>2)continue;
			int rt=0;
			for(int i=1;i<=n;i++){
				if(s[i])minn[i]=0,rt=i;
			}
			dfs2(rt,0);
			int tmp=0;
			for(int i=1;i<=n;i++){
				tmp=max(tmp,minn[i]);
			}
			ans=min(ans,tmp);
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		cnt=1;
	}
}
