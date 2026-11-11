#include <iostream>
#include <vector>
#include <queue>
const int inf=1e9+7;
int get(int x){
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1; 
	}
	return ans;
}
int n,k;
std::vector<int> G[111];
std::vector<int> d(111);
std::vector<bool> vis(111);
void dfs(int u,int fa){
	vis[u]=1;
	d[u]=std::min(d[fa]+1,d[u]);
	for(auto v:G[u]){
		if(!vis[v]) dfs(v,u);
	}
}
int cnt[111];
void dfs2(int u,int fa,int count){
	cnt[u]=0;
	for(auto v:G[u]){
		if(v!=fa){
			if(vis[v]==1&&vis[u]==0){
				dfs2(v,u,count+1);
			}
			dfs2(v,u,count);
		}
	}
}
bool valid(std::vector<int> T){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	for(auto u:T){
		vis[u]=1;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs2(i,0,0);
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]>2) return false;
	}
	return true;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	std::cin>>c>>t;
	while(t--){
		std::cin>>n>>k;
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			std::cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int ans=inf;
		for(int mask=0;mask<(1<<n);mask++){
			if(get(mask)!=k) continue;
			for(int i=1;i<=n;i++){
				d[i]=inf;
				vis[i]=false;
			}
			std::vector<int> T;
			d[0]=-1;
			for(int j=0;j<30;j++){
				if((mask>>j)&1){
					//dfs(j+1,0);
					d[j+1]=0;
					T.push_back(j+1);
				}
			}
			std::queue<int> q;
			if(!valid(T)) continue;
			for(auto u:T){
				q.push(u);
			}
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(auto v:G[u]){
					if(d[v]>d[u]+1){
						d[v]=d[u]+1;
						q.push(v);
					}
				}
			}
			int cur=0;
			for(int i=1;i<=n;i++){
				cur=std::max(cur,d[i]);
			}
			ans=std::min(ans,cur);
		}
		std::cout<<ans<<'\n';
	}
	return 0;
}
