#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>e[1005];
int dis[1005][1005];
bitset<1005>use;
int ans;
bitset<1005>vis;
void dfs(int u){
	vis.set(u);
	for(int x:e[u]){
		if(!vis[x]&&use[x]){
			dfs(x);
		}
	}
}
bool ck(){
	vis.reset();
	int s=0;
	for(int i=0;i<n;i++){
		if(!vis[i]&&use[i]){
			if(++s>2){
				return 0;
			}
			dfs(i);
		}
	}
	return 1;
}
void work(int tp,int p){
	if(tp--==0){
		if(!ck()){
			return ;
		}
		int ma=0;
		for(int i=0;i<n;i++){
			if(use[i]){
				continue;
			}
			int mi=1e9;
			for(int j=0;j<n;j++){
				if(use[j]){
					mi=min(mi,dis[i][j]);
				}
			}
			ma=max(ma,mi);
		}
		ans=min(ans,ma);
		return ;
	}
	for(int i=p;i<n-tp;i++){
		use.set(i);
		work(tp,i+1);
		use.reset(i);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			e[i].clear();
			for(int j=i+1;j<n;j++){
				dis[i][j]=dis[j][i]=1e9;
			}
		}
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x--;
			y--;
			e[x].emplace_back(y);
			e[y].emplace_back(x);
			dis[x][y]=dis[y][x]=1;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j){
					continue;
				}
				for(int k=0;k<n;k++){
					if(i==k||j==k){
						continue;
					}
					dis[j][k]=dis[k][j]=min(dis[j][k],dis[j][i]+dis[i][k]);
				}
			}
		}
		ans=1e9;
		work(k,0);
		printf("%d\n",ans);
	}
}
