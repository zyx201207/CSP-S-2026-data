#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
const int N=1e5+10;
int c,T,n,k;
struct Node {
	int to,nxt;
	Node() {
		to=nxt=0;
	}
	Node(int a,int b) {
		to=a,nxt=b;
	}
} adj[N<<1];
int head[N],idx;
bool vis[N],vis2[N];
int sz[N],son[N],m,b[N],ans,minx,maxx;
inline void add(int x,int y) {
	adj[++idx]=Node(y,head[x]);
	head[x]=idx;
	return ;
} 
inline void dfs2(int u,int fa) {
	vis2[u]=1;
	for(int i=head[u];i;i=adj[i].nxt) {
		int v=adj[i].to;
		if(v==fa||vis2[v]||!vis[v])
			continue;
		dfs2(v,u);
	}
	return ;
}
inline void dfs3(int u,int fa,int stp) {
	vis2[u]=1;
	for(int i=head[u];i;i=adj[i].nxt) {
		int v=adj[i].to;
		if(v==fa||vis2[v]) continue;
		if(vis[v]) {
			minx=min(minx,stp+1);
			continue;
		}
		dfs3(v,u,stp+1);
	}
	return ;
} 
inline void dfs(int stp) {
	if(stp>k) {
		for(int i=1;i<=n;i++)
			vis2[i]=0;
		int cnt=0;
		bool flag=1;
		for(int i=1;i<=n;i++) {
			if(cnt<2) {
				if(vis[i]&&!vis2[i])
					dfs2(i,0);
				cnt++;
			} else {
				if(vis[i]) {
					flag=0;
					break;
				}
			}
		}
		if(flag) {
			int maxx=0;
			for(int i=1;i<=n;i++) {
				if(vis[i]) continue;
				for(int j=1;j<=n;j++)
					vis2[j]=0;
				minx=inf;
				dfs3(i,0,0);
				maxx=max(minx,maxx);
			}
			ans=min(ans,maxx);
		}
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=1;
			b[stp]=i;
			dfs(stp+1);
			vis[i]=0;
		}
	}
	return ;
}
//inline bool check(int x) {
//	bool flag=0;
//	for(int i=1;i<=n;i++) {
//		if(son[u]==2) {
//			
//		}
//	}
//	return flag;
//}
//inline void dfs(int u,int fa) {
//	sz[u]=1;
//	for(int i=head[u];i;i=adj[i].nxt) {
//		int v=adj[i].to;
//		if(v==fa) continue;
//		dfs(v,u);
//		sz[u]+=sz[v];
//		son[u]++;
//	}
//	return ;
//}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--) {
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++) {
			int x,y;
			scanf("%lld%lld",&x,&y);
			add(x,y),add(y,x);
		}
//		if(c==13||c==14) {
//			
//		}
//		dfs(1,0); 
//		int l=0,r=n+1;
//		while(l+1<r) {
//			int mid=(l+r)>>1;
//			if(check(mid))
//				r=mid;
//			else l=mid;
//		} 
//		printf("%lld\n",r);
		ans=inf;
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
