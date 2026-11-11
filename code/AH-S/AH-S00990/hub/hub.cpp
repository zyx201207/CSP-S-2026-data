#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int cid,T;
int n,k;
struct edges{int to,next;}edge[2*N];
int head[N],kk;
void insert(int a,int b){edge[++kk]=(edges){b,head[a]},head[a]=kk;}
bool vis[N];
int dp[N][2],id[N][2];
int now,Iu,Iv,f[N];
int ii[N],Fa[N];
pair<int,int> e[N];
void dfs(int u,int fa){
	f[u]=fa;
	dp[u][0]=dp[u][1]=0,id[u][0]=id[u][1]=u;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa||vis[v]) continue;
		dfs(v,u);
		if(dp[v][0]+1>dp[u][0]) dp[u][1]=dp[u][0],dp[u][0]=dp[v][0]+1,id[u][1]=id[u][0],id[u][0]=id[v][0];
		else if(dp[v][0]+1>dp[u][1]) dp[u][1]=dp[v][0]+1,id[u][1]=id[v][0];
	}
	if(dp[u][0]+dp[u][1]>now){
		now=dp[u][0]+dp[u][1],Iu=id[u][0],Iv=id[u][1];
	}
}
int dfs2(int u,int fa,int d){
	dp[u][0]=0;
	int res=0;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa||vis[v]) continue;
		res+=dfs2(v,u,d);
		dp[u][0]=max(dp[u][0],dp[v][0]+1);
	}
	return res+(dp[u][0]>=d);
}
int solve(int rt,int fa,int d){
	vis[fa]=1;
	now=-1;dfs(rt,fa);
	for(int i=1;i<=now/2;++i) Iu=f[Iu];
	// printf("%d %d %d\n",rt,fa,u);
	int res=max(1,dfs2(Iu,0,d));
	vis[fa]=0;
	return res;
}
int chk(int u,int v,int d){return solve(u,v,d)+solve(v,u,d);}
int Gt(int x,int y,int lim){
	if(chk(x,y,lim-1)>k) return lim;
	int l=1,r=lim-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(x,y,mid)<=k) r=mid-1;else l=mid+1;				
	}
	return l;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&cid,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i) head[i]=0;kk=0;
		for(int i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			insert(x,y),insert(y,x);
			e[i]=make_pair(x,y);
		}
		if(k==n){printf("0\n");continue;}
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(solve(1,0,mid)<=k) r=mid-1;else l=mid+1;				
		}
		int ans=l,rt=Iu;
		if(n<=4000){
			for(int i=1;i<n;++i) ans=Gt(e[i].first,e[i].second,ans);
		}
		else{
			dfs(rt,0);
			for(int i=1;i<=n;++i) ii[i]=i,Fa[i]=f[i];
			sort(ii+1,ii+1+n,[](int x,int y){return dp[x][0]>dp[y][0];});
			for(int i=2;i<=100;++i) ans=Gt(ii[i],Fa[ii[i]],ans);
		}
		printf("%d\n",ans);
	}
	return 0;
} 
