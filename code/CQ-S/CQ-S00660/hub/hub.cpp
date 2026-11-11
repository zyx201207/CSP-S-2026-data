#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D long double
#define N 2000006
int head[N],nxt[N],ver[N],tot;
void add(int x,int y){
	ver[++tot]=y;
	nxt[tot]=head[x];head[x]=tot;
}
int n,k,dep[N],sz[N],pos,mxd[N],rot,fth[N];
void dfs1(int x,int fa){
	sz[x]=1;dep[x]=dep[fa]+1;
	mxd[x]=dep[x];fth[x]=fa;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)	continue;
		dfs1(y,x);sz[x]+=sz[y];mxd[x]=max(mxd[x],mxd[y]);
	}
}
void dfs2(int x,int fa){
	int zt=(2*(n-sz[x])<=n);
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)	continue;
		dfs2(y,x);zt&=(2*sz[y]<=n);
	}
	if(zt)	pos=x;
}
int dp[N],V;//dp[i]:钦定i为连通块根节点时，覆盖i的子树至少需要多少(i必选)
void dfs(int x,int fa){
	dp[x]=1;//必选 
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)	continue;
		dfs(y,x);
		if((mxd[y]-dep[x])>V)	dp[x]+=dp[y];
	}
}
pair<int,int> tmp[N];
int vis[N];
void bfs(int x){
	queue<int> q;q.push(x);vis[x]=V+1;
	while(q.size()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			if(vis[y]<vis[x]-1){
				vis[y]=vis[x]-1;q.push(y);
			}
		}
	}
}
int up[N],dn[N];
int dfst(int x,int tv,int fa){
	int go=up[x];
	int cst=max(0,dn[go]-V);
	if(tv+cst+dp[x]<=k)	return 1;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)	continue;
		int v=dfst(y,tv,x);
		if(v)	return 1;
	}
	return 0;
}
int del[N],cnt[4003][4003];
int chk(int x,int fa,int d1,int d2){
	if((x==d1)||(x==d2))	return 1;
	if(!vis[x])	return 0;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)	continue;
		int v=chk(y,x,d1,d2);
		if(!v)	return 0;
	}
	return 1;
}
inline int getans(){
	if(k==2){
		int sum=0;
		for(int i=1;i<=n;i++)	vis[i]=0;
		for(int i=n;i>=1;i--){
			if(!vis[tmp[i].second]){
				if(sum==2)	return 0;
				int p=tmp[i].second;
				for(int j=1;j<=V;j++)	p=fth[p];
				if(!p)	p=1;
				bfs(p);sum++;
			}
		}
		return 1;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)	cnt[i][j]=0;
	for(int rot=1;rot<=n;rot++){
		dfs1(rot,0);dfs(rot,0);
		if(dp[rot]<=k)	return 1;
		up[rot]=rot;dn[rot]=0;
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++)	del[j]=0;
			int p=i;
			while(p)	del[p]=1,p=fth[p];
			for(int j=1;j<=n;j++)if(!del[j]){
				if(cnt[i][j])	continue;
				cnt[i][j]=1;
				if(dp[i]+dp[j]>k)	continue;
				for(int k=1;k<=n;k++)	vis[k]=0;
				bfs(i);bfs(j);
				if(!chk(rot,0,i,j))	continue;
				return 1;
			}
		}
	}
	return 0;
}
inline void solve(){
	cin>>n>>k;dep[0]=-1;//深度0-based 
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;add(x,y);add(y,x);
	}
	dfs1(1,0);dfs2(1,0);rot=pos;dfs1(rot,0);
	for(int i=1;i<=n;i++){
		tmp[i]={dep[i],i};
	}
	sort(tmp+1,tmp+n+1);
	int l=0,r=n,ans=n;
	while(l<r){
		int mid=(l+r)>>1;V=mid;
		if(getans())	r=ans=mid;
		else	l=mid+1;
	}
	cout<<ans<<"\n";
}
inline void cln(){
	tot=0;
	for(int i=1;i<=n;i++)	head[i]=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int id,T;cin>>id>>T;
	while(T--)	solve(),cln();
	return 0;
}
/*int can[N];
void dfsc(int x,int fa,int dst){
	if(dst>V)	return;
	can[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)	continue;
		dfsc(y,x,dst+1);
	}
}*/
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
