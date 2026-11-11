#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int ans;
int x[2000005];
int vis[2000005];
int dis[2000005];
vector<int> e[1000005];
int bfs(int u){
	queue<pair<int,int>> p;
	p.push({u,0});
	dis[u]=0;
	while(!p.empty()){
		int q=p.front().first;
		int l=p.front().second;
		p.pop();
		int newn=e[q].size();
		for(int i=0;i<newn;i++){
			int to=e[q][i];
			if(vis[to]!=0 && dis[to]==l+1){
				vis[to]++;
			}else if(vis[to]==0 || dis[to]>l+1){
				
				dis[to]=l+1;
				vis[to]=1;
			}
			p.push({to,l+1});
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==2){
			ans++;
		}
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&d);
		memset(x,0,sizeof(x));
		memset(e,0,sizeof(e));
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
			for(int j=1;j<=d && i-j>0;j++){
				if(x[i]-x[i-j]>d){
					break;
				}
				e[i-j].push_back(i);
			}
		}
		for(int i=1;i<=n-3;i++){
			memset(vis,0,sizeof(vis));
			memset(dis,0,sizeof(dis));
			bfs(i);
		}
		printf("%d\n",ans);
	}
}
