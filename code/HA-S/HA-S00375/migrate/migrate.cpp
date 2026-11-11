#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){int x;scanf("%lld",&x);return x;}
const int N=4e3+10;
const int inf=0x3f3f3f;
int dis[N][N];
vector<pair<int,int> > g[N];
int w[N];
void dij(int s){
	memset(dis,0x3f3f3f,sizeof(dis));
	dis[s][s]=0;
	priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push({0,s});
	while(pq.size()){
		int d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(d>dis[u][s]) continue;
		for(auto w:g[u]){
			if(dis[u][s]>dis[u][s]+w.first){
				dis[w.second][s]=dis[u][s]+w.first;
				pq.push({dis[w.second][s],w.second});
			}
		}
	}
}
int vis[N];
int dfs(int u,int y,int fa,int num,int anss){
	for(auto w:g[u]){
		int v=w.first;
		if(vis[v]||fa==v) continue;
		vis[v]=1;
		num+=dis[u][w.first];
		if(num==dis[u][v]){
			anss++;
		}
		dfs(w.first,y,u,num,anss);
	}
	return anss;
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		int n=read(),d=read();
		for(int i=0;i<n;i++) g[i].clear(); 
		for(int i=1;i<=n;i++){
			w[i]=read();
			for(int j=i-1;j>=1;j--){
				if(w[i]-w[j]<=d){
					g[i].push_back({j,1});
					g[j].push_back({i,1});
				}
			}
		}
		for(int i=1;i<=n;i++){
			dij(i);
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				memset(vis,0,sizeof(vis));
				if(dfs(i,j,0,0,0)==2) sum++;
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
