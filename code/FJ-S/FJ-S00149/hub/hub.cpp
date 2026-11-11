#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,T,n,k,dis[N],bel[N],ans=1<<30,h[N];
vector<int>e[N];
bool vis[N];
bool b[200][200],qwq[N],on[N];
void DFS(int u){
	on[u]=1;
	for(auto v:e[u]){
		if(on[v]||!qwq[v])continue;
		DFS(v);
	}
}
void dfs(int i){
//	printf("i:%d\n",i);
	if(i==n+1){
	//	printf("I:%d\n",i);
		int cnt=0;
		for(int j=1;j<=n;j++)qwq[j]=on[j]=0;
		for(int j=1;j<=n;j++)
			if(vis[j])cnt++,h[cnt]=j,qwq[j]=1;
	//		printf("cnt:%d\n",cnt);
		if(cnt!=k)return;
		int lian=0;
		for(int j=1;j<=cnt;j++)
			if(!on[h[j]])
				DFS(h[j]),lian++;
		if(lian>2)return;
		queue<int>q;	
		for(int j=1;j<=n;j++){
			dis[j]=1<<30;
			if(vis[j])dis[j]=0,q.push(j);
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:e[u]){
				if(dis[v]==1<<30){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		int mx=0;
		for(int j=1;j<=n;j++)mx=max(mx,dis[j]);
		ans=min(ans,mx);
	//	puts("6666");
		return; 
	}
	vis[i]=0;
	dfs(i+1);
	vis[i]=1;
	dfs(i+1);
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)vis[i]=0,e[i].clear();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)b[i][j]=0;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		b[u][v]=b[v][u]=1;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans=1<<30;
	dfs(1);
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	for(;T--;)solve();
}
