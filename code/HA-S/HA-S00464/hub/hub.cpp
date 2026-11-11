#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

const int N=1000006;

int n,k;
struct node{
	int to,nxt;
}edg[2*N];
int cnt_edg,h[N];
void add(int u,int v){
	edg[++cnt_edg]={v,h[u]};
	h[u]=cnt_edg;
}
int rt;
int dis[15][15];
void dfs(int x,int fa,int disq){
	dis[rt][x]=disq;
	for(int i=h[x];i;i=edg[i].nxt){
		int y=edg[i].to;
		if(y==fa)continue;
		dfs(y,x,disq+1);
	}
}
int p[N];
int vis[N];
void dfs2(int x){
	vis[x]=1;
	for(int i=h[x];i;i=edg[i].nxt){
		int y=edg[i].to;
		if(vis[y])continue;
		if(!p[y])continue;
		dfs2(y);
	}
}
int ans=0;
void dfs1(int x,int cnt){
	if(cnt==k){
		for(int i=1;i<=n;i++)vis[i]=0;
		int cnt=0;
		for(int i=1;i<=n&&cnt<=2;i++){
			if(!p[i])continue;
			if(vis[i])continue;
			dfs2(i);
			++cnt;
		}
		if(cnt!=2)return;
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(p[i])continue;
			int minn=1e9;
			for(int j=1;j<=n;j++){
				if(!p[j])continue;
				minn=min(minn,dis[i][j]);
			}
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);
		return;
	}
	if(x==n+1)return;
	p[x]=1;
	dfs1(x+1,cnt+1);
	p[x]=0;
	dfs1(x+1,cnt);
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++){
		rt=i;
		dfs(i,0,0);
	}
	ans=1e9;
	dfs1(1,0);
	printf("%d\n",ans);
	for(int i=1;i<=cnt_edg;i++)edg[i]={0,0};
	for(int i=1;i<=n;i++)h[i]=0;
	cnt_edg=0;
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--){
		solve();
	}
	return 0;
}
