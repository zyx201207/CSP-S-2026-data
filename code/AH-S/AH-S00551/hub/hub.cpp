#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,mn;
bool vis[N],vis2[N];
int dis[N];
vector<int> G[N];
queue<int> q;
void dfs2(int x,int fa){
	vis2[x]=0;
	for(auto y:G[x]){
		if(y!=fa){
			dfs2(y,x);
		}
	}
}
int bfs(){
	while(!q.empty()) q.pop();
	fill(dis+1,dis+n+1,-1);
	for(int i=1;i<=n;i++){
		if(vis[i]){
			q.push(i);
			dis[i]=0;
		}
	}
	int ans=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		ans=max(ans,dis[u]);
		for(auto v:G[u]){
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return ans;
}
void dfs(int x,int y){
	if(x==n+1){
		if(y!=0){
			return;
		}
		for(int i=1;i<=n;i++){
			vis2[i]=vis[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis2[i]){
				dfs2(i,i);
				cnt++;
			}
		}
		if(cnt>2) return;
		if(mn!=-1) mn=min(mn,bfs());
		else mn=bfs();
		return;
	}
	if(y){
		vis[x]=1;
		dfs(x+1,y-1);
	}
	vis[x]=0;
	dfs(x+1,y);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		mn=-1;
		for(int i=1;i<=n;i++) G[i].clear();
		scanf("%d%d",&n,&k);
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,k);
		printf("%d\n",mn);
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
/*
 * 0 2
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
9 10*/
