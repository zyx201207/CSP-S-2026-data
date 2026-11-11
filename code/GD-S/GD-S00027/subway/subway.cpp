#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
const int M=500010;
int t[N][M];
int c,n,m,d,q;
int w[M];
struct Node{
	vector<int> to;
	vector<int> id;
};
Node sub[M];
bool vis[M];
ll dp[N][M];

inline ll dfs(int p,int de,int now,int fa){
	//printf("%d %d %d\n",p,de,now);
	if(p==de){
		//printf("why%d\n",t[now][de]);
		return t[now][de];
	}
	if(dp[now][p]!=-1){
		return dp[now][p];
	}
	vis[p]=true;
	ll ans=0x3f3f3f3f3f3f3f3fLL;
	for(int y=0;y<(int)sub[p].to.size();++y){
		int tonum=sub[p].to[y];
		int toid=sub[p].id[y];
		if(tonum!=fa&&!vis[tonum]){
			if(now==0){
				ans=min(ans,t[toid][p]+dfs(tonum,de,toid,p));
			}
			else{
				if(now==toid){
					ans=min(ans,dfs(tonum,de,now,p));
				}
				else{
					//printf("mabe%d %d %d\n",t[now][p],t[toid][p],dfs(tonum,de,toid));
					ans=min(ans,t[now][p]+t[toid][p]+dfs(tonum,de,toid,p));
				}
			}
		}
		//printf("%din%d\n",p,ans);
	}
	//printf("%d %d %d %d\n",p,de,now,ans);
	vis[p]=false;
	dp[now][p]=ans;
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		int a=0;
		for(int j=1;j<=k;j++){
			int x;
			scanf("%d",&x);
			scanf("%d",&t[i][x]);
			if(a){
				sub[a].to.push_back(x);
				sub[a].id.push_back(i);
				sub[x].to.push_back(a);
				sub[x].id.push_back(i);
			}
			a=x;
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		memset(vis,false,sizeof(vis));
		memset(dp,-1,sizeof(dp));
		printf("%lld\n",w[x]+w[y]+dfs(x,y,0,0));
	}
}
