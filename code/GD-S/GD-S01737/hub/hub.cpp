#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
vector<int> graph[100005];
int dis[5005][5005];
int dep[5005],st[5005][20];
int temp[5005];
bool vis[5005];
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	st[u][0]=fa;
	for(int i=1;i<20;i++) st[u][i]=st[st[u][i-1]][i-1];
	for(int v:graph[u]){
		if(v==fa) continue;
		dfs1(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[st[x][i]]>=dep[y]) x=st[x][i];
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(st[x][i]!=st[y][i]) x=st[x][i],y=st[y][i];
	}
	return st[x][0];
}
void dfs(int u,int fa,int tmp){
	vis[u]=true;
	for(int v:graph[u]){
		if(v==fa||!(tmp&(1<<(v-1)))) continue;
		dfs(v,u,tmp);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(c==7){
		while(T--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				graph[u].push_back(v);
				graph[v].push_back(u);
				
			}
		}
	}
	while(T--){
		memset(dis,0,sizeof(dis));
		memset(dep,0,sizeof(dep));
		memset(st,0,sizeof(st));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		dfs1(1,0);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=dis[j][i]=dep[i]+dep[j]-2*dep[lca(i,j)];
			}
		}
		int ans=INT_MAX;
		for(int i=1;i<(1<<n);i++){
			if(__builtin_popcount(i)!=k) continue;
			memset(vis,false,sizeof(vis));
			int flag=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))&&!vis[j]) flag++,dfs(j,0,i); 
			}
			if(flag>2) continue;
			memset(temp,0x3f,sizeof(temp));
			int res=0;
			int li=i,id=1;
			while(li){
				if(li&1){
					for(int j=1;j<=n;j++) temp[j]=min(temp[j],dis[id][j]);
				}
				li>>=1;
				id++;
			}
			for(int j=1;j<=n;j++) res=max(res,temp[j]);
			ans=min(ans,res);
		//	cout<<i<<' '<<res<<'\n';
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) graph[i].clear();
	}
	return 0;
}
/*
100+100+30+5=235
*/
