#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,dis[N];
bool p[N],vis[N];
vector<int>adj[N];
void dfs(int x,int fa){
	vis[x]=1;
	for(int y:adj[x])
		if(p[y]&&y!=fa)dfs(y,x);
}
void dfs2(int x,int fa,int d){
	dis[x]=min(dis[x],d);
	for(int y:adj[x])
		if(y!=fa)dfs2(y,x,d+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)adj[i].clear();
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			adj[x].emplace_back(y),adj[y].emplace_back(x);
		}
		if(n<=10){
			int mn=1e9;
			for(int i=0;i<(1<<n);++i){
				int cnt=0;
				for(int j=0;j<n;++j)
					if(i>>j&1)p[j+1]=1,cnt++;
					else p[j+1]=0;
				if(cnt!=k)continue;
				for(int j=1;j<=n;++j)vis[j]=0,dis[j]=1e9;
				cnt=0;
				for(int j=1;j<=n;++j)
					if(p[j]&&!vis[j])dfs(j,0),cnt++;
				if(cnt>2)continue;
				for(int j=1;j<=n;++j)
					if(p[j])dfs2(j,0,0);
				int mx=0;
				for(int j=1;j<=n;++j)mx=max(mx,dis[j]);
				mn=min(mn,mx);
			}
			printf("%d\n",mn);
		}
	}
	return 0;
}
