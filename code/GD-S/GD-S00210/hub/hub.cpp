#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
int c,T,n,k,rt,dis[1000005],ans=1e9;
vector<int>e[1000005];
void dfs(int x,int k){
	if(dis[x]<=k)return;
	dis[x]=k;
	for(int i=0;i<(int)e[x].size();i++)dfs(e[x][i],k+1);
	return;
}
int main(){
	srand(time(0));
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--){
		ans=1e9;
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1,u,v;i<n;i++){
			scanf("%d %d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		bool f=true;
		for(int i=1;i<=n;i++)dis[i]=1e9;
		rt=rand()%n+1;
		dfs(rt,0);
		for(int i=1;i<k;i++){
			// for(int j=1;j<=n;j++)printf("%d ",dis[j]);
			// printf("\n");
			rt=0;
			for(int j=1;j<=n;j++)if(dis[j]>dis[rt] && dis[j]>1)rt=j;
			if(rt==0)f=false;
			dfs(rt,0);
		}
		// for(int j=1;j<=n;j++)printf("%d ",dis[j]);
		// printf("\n");
		rt=0;
		for(int i=1;i<=n;i++)if(dis[i]>dis[rt])rt=i;
		if(f)ans=min(ans,dis[rt]);
		
		printf("%d\n",ans);
	}
	return 0;
}
