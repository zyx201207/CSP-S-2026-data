#include<bits/stdc++.h>//15pts
using namespace std;
const int N=11;
vector<int>g[N];
bool f[N];
int dis[N];
int n,m;
int dfs(int u,int dad,int top){
	dis[u]=min(dis[u],top);
	f[u]=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==dad){
			continue;
		}
		if(top&&f[v]==1){
			continue;
		}
		dfs(v,u,(top==0&&f[v]==1)?0:(top+1));
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	scanf("%*d%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int ans=n;
		for(int i=0;i<(1<<n);i++){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1){
					cnt++;
					f[j]=1;
				}else{
					f[j]=0;
				}
				dis[j]=n;
			}
			if(cnt!=m){
				continue;
			}
			cnt=0;
			for(int j=1;j<=n;j++){
				if(f[j]==0){
					continue;
				}
				cnt++;
				dfs(j,0,0);
			}
			if(cnt>2){
				continue;
			}
			int maxx=0;
			for(int j=1;j<=n;j++){
				maxx=max(maxx,dis[j]);
			}
			ans=min(ans,maxx);
		}
		printf("%d\n",ans);
	}
	return 0;
}
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

I love Yore_Snow!!!!!
*/
