#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=2e6+5;
int n,k;
int xx;
vector<int>ed[MAXN];
int dp[MAXN];
int dis[MAXN],dep[MAXN];
void dfs(int x,int fa){
	dis[x]=1;
	for(int i=0;i<ed[x].size();i++){
		if(ed[x][i]==fa)continue;
		dep[ed[x][i]]=dep[x]+1;
		dfs(ed[x][i],x);
		dis[x]=max(dis[x],dis[ed[x][i]]+1);
	}
}
void dfs2(int x,int fa){
	dp[x]=1;
	for(int i=0;i<ed[x].size();i++){
		if(ed[x][i]==fa)continue;
		dfs2(ed[x][i],x);
		if(dis[ed[x][i]]<=xx)continue;
		dp[x]+=dp[ed[x][i]];
	}
}
int dfs3(int x,int fa,int lim){
	if(lim<dep[x])return 1e9;
	int minn=dp[x];
	int maxn=-1e9,secmaxn=-1e9;
	if(dep[x]>xx)maxn=0;
	for(int i=0;i<ed[x].size();i++){
		if(ed[x][i]==fa||dis[ed[x][i]]+dep[x]<=xx)continue;
		if(maxn<dis[ed[x][i]]){
			secmaxn=maxn;maxn=dis[ed[x][i]];
		}else{
			if(secmaxn<dis[ed[x][i]]){
				secmaxn=dis[ed[x][i]];
			}
		}
	}
	for(int i=0;i<ed[x].size();i++){
		if(ed[x][i]==fa||dis[ed[x][i]]+dep[x]<=xx)continue;
		minn=min(minn,dfs3(ed[x][i],x,min(lim,
		xx+dep[x]-(maxn==dis[ed[x][i]]?secmaxn:maxn))));
	}
	return minn;
}
bool check(int X){
	xx=X;
	int minn=1e9+888;
	for(int i=1;i<=n;i++){
		dep[i]=0;
		for(int i=1;i<=n;i++)dp[i]=0;
		dfs(i,0);
		dfs2(i,0);
		for(int j=0;j<ed[i].size();j++){
			minn=min(minn,dp[i]-dp[ed[i][j]]+dfs3(ed[i][j],i,1e9));
		}
		if(minn<=k)return true;
		if(n>=2000&&i>=1000000/n)return false;
	}
	return minn<=k;
}
void did(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)ed[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	int l=0,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	printf("%d\n",l);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--){
		did();
	}
}
