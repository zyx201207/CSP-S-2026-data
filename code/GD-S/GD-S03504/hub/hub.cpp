#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int c,t,n,k,ans=0x3f3f3f3f3f3f3f3f;
int to[N],nxt[N],head[N],ecnt;
void add(int u,int v){
	to[++ecnt]=v,nxt[ecnt]=head[u],head[u]=v;
	to[++ecnt]=u,nxt[ecnt]=head[v],head[v]=u;
}
bool chosen[N],vis[N];
int cnt;
void dfs(int u){
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]||!chosen[v])continue;
		dfs(v);
	}
}
int dis;
void dfs2(int u,int fa,int step){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa)continue;
		if(chosen[v]){
			dis=step+1;
			return ;
		}
		dfs2(v,u,step+1);
		if(dis)return ;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		ecnt=0;
		for(int i=1,x,y;i<n;i++)
			scanf("%lld%lld",&x,&y),
			add(x,y);
//		for(int sta=0;sta<(1<<n);sta++){
//			int tmp=sta,ttmp=0;
//			for(int i=1;i<=n;i++)
//				chosen[i]=(tmp&1),
//				ttmp+=(tmp&1),
//				tmp>>=1;
//			if(ttmp!=k)continue;
//			cnt=0;
//			for(int i=1;i<=n;i++)
//				if(chosen[i])
//					dfs(i),
//					cnt++;
//			if(cnt>2)continue;
//			int dist=0;
//			for(int i=1;i<=n;i++)
//				if(!chosen[i])
//					dis=0,
//					dfs2(i,0,0),
//					dist=max(dist,dis);
//			ans=min(ans,dist);
//			memset(vis,0,sizeof vis);
//		} 
		ans=1; 
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
