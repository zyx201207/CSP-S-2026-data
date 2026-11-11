#include<bits/stdc++.h>
#define LL long long int 
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e2+10;
int c,n,k,ans;
int dis[N];
bool vis[N],in[N];
vector<int> g[N];
queue<int> q;
int pc(int x){
	int cnt=0;
	while(x){
		if(x&1) cnt++;
		x>>=1;
	}
	return cnt;
}
void dfs(int u,int fa){
	vis[u]=true;
	for(int v:g[u]){
		if(v==fa) continue;
		if(!in[v]) continue;
		dfs(v,u);
	}
}
void bfs(){
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(dis[v]!=INF) continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
}
void Main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=INF;
	for(int i=0;i<(1<<n);i++){
		if(pc(i)!=k) continue;
		int cp=0;
		memset(in,0,sizeof in);
		for(int j=1;j<=n;j++)
			if(i&(1<<j-1)) in[j]=true;
		memset(vis,0,sizeof vis);
		for(int j=1;j<=n;j++){
			if(!in[j]) continue;
			if(vis[j]) continue;
			dfs(j,0);
			cp++;
		}
		if(cp!=2) continue;
		memset(dis,0x3f,sizeof dis);
		while(q.size()) q.pop();
		for(int j=1;j<=n;j++){
			if(in[j]){
				q.push(j);
				dis[j]=0;
			}
		}
		bfs();
		int res=0;
		for(int j=1;j<=n;j++) res=max(res,dis[j]);
		ans=min(ans,res);
	}
	printf("%d\n",ans);
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	scanf("%d%d",&c,&T);
	while(T--) Main();
	return 0;
}
