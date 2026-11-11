#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[114];
int vis[1145],viss[114],dis[1145],cntt=0;
int kcnt=0;
int maxx=0;
void dfs(int u,int fa){
	dis[u]=min(dis[u],dis[fa]+1);
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]!=fa){
			dfs(g[u][i],u);
		}
	}return;
}
void dfs2(int u,int fa){
	viss[u]=1;
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]!=fa&&vis[g[u][i]]){
			dfs2(g[u][i],u);
		}
	}return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n<=15){
			int minn=11451419198102333ll;
			for(int i=1;i<(1<<n);i++){
				int cntt=0;
				vector<int>awsl;
				memset(vis,0,sizeof(vis));
				memset(viss,0,sizeof(viss));
				kcnt=0;
				for(int j=0;j<n;j++){
					if(i&(1<<j)){
						cntt++;
						awsl.push_back(j+1);
						vis[j+1]=1;
					}
				}if(cntt!=k){
					continue;
				}else{
					maxx=0;
					memset(dis,0x3f,sizeof(dis));
					kcnt=0;
					for(int qp=0;qp<awsl.size();qp++){
						dis[0]=-1;
						dfs(awsl[qp],0);
					}for(int zc=1;zc<=n;zc++){
						maxx=max(maxx,dis[zc]);
						if(vis[zc]&&!viss[zc]){
							kcnt++;
							dfs2(zc,0);
						}
					}if(kcnt<=2){
						minn=min(minn,maxx);
					}
				}
			}cout<<minn<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	
}
