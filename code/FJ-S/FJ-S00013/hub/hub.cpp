#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;

const int N=1e6+10;
const int INF=1e9;
int c,t,idx,timer;
int n,k;
int head[N],dfn[N],dis[N],tag[N];
int st[21][N];
int stk[N],top;
int ans;
bool vis[N];

struct edge{
	int to,nxt;
}e[N<<1];

void init(){
	idx=1;
	rep(i,1,n){
		head[i]=0;
		dfn[i]=0;
		for(int j=0;j<=20;++j){
			st[j][i]=0;
		}
		stk[i]=0;
	}
	top=0;
	ans=INF;
}

void add_edge(int u,int v){
	++idx;
	e[idx].to=v;
	e[idx].nxt=head[u];
	head[u]=idx;
}

void dfs(int x,int fa){
	st[0][dfn[x]=++timer]=fa;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa)continue;
		dfs(y,x);
	}
}

int get(int x,int y){
	return (dfn[x]<dfn[y]?x:y);
} 

void init_lca(){
	for(int j=1;(1<<j)<=n;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			st[j][i]=get(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	} 
}

int lca(int x,int y){
	if(x==y)return x;
	if(dfn[x]+1>dfn[y])swap(x,y);
	int l=dfn[x]+1,r=dfn[y];
	int k=__lg(r-l+1);
	return get(st[k][l],st[k][r-(1<<k)+1]); 
} 

void dfs3(int x){
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(vis[y])continue;
		if(!tag[y])continue;
		dfs3(y);
	}
}

void solve(){
	rep(i,1,n){
		vis[i]=0;
		dis[i]=INF;
		tag[i]=0;
	}
	rep(i,1,top){
		tag[stk[i]]=1;
	} 
	if(n>=3){
//		bool ok=1;
//		int j=1;
		rep(_,1,2){
			int id=-1;
			rep(i,1,top){
				if(!vis[stk[i]]){
					id=stk[i];
				}
			}
			if(id==-1)break;
			dfs3(id);
//			if(j>top)break;
//			dfs3(j-1);
		}
		rep(i,1,top){
			if(vis[stk[i]]==0)return ;
		}
	} 
	queue<int> q;
	rep(i,1,top){
		dis[stk[i]]=0;
		q.push(stk[i]);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(dis[y]!=INF)continue;
			dis[y]=dis[x]+1;
			q.push(y); 
		}
	}
//	printf("hello\n");
	int mx=0;
	rep(i,1,n)mx=max(mx,dis[i]);
	ans=min(ans,mx);
}

void dfs2(int now,int cnt){
	if(cnt+n-now+1<k)return ;
	if(now==n+1){
		if(cnt!=k)return ;
		/*
		printf("fenzu:");
		rep(i,1,top)printf("%d ",stk[i]);
		cout<<'\n';
		*/
		solve();
		return ;
	}
	dfs2(now+1,cnt);
	stk[++top]=now;
	dfs2(now+1,cnt+1);
	stk[top--]=0;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	rep(_,1,t){
		scanf("%d %d",&n,&k);
		init();
		rep(i,1,n-1){
			int u,v;
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		dfs(1,0);
		init_lca();
		dfs2(1,0);
		printf("%d\n",ans);
	} 
	return 0;
}

