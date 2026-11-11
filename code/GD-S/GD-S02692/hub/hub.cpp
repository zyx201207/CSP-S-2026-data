#include<bits/stdc++.h>
using namespace std;
int c,t,dis[305][305],n,k,sm,ans;
vector<int> e[305];
vector<int> choose;
void dfs(int u,int fa,int now){
	if(u!=fa) dis[now][u]=dis[now][fa]+1;
	for(int v:e[u]){
		if(v==fa) continue;
		dfs(v,u,now);
	}
}
void dfs1(int c,int w){
	if(c==0){
		int cnt=choose.size(),vis[n+1][n+1];
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) vis[i][j]=0;
		for(int v:choose){
			for(int u:e[v]){
				for(int q:choose){
					if(q==v) continue;
					if(u==q&&vis[u][v]==0&&vis[v][u]==0) cnt--,vis[u][v]=1,vis[v][u]=1;
				}
			}
		}
		
		if(cnt<=2){
			int d[n+1];
			fill(d,d+n+1,2e9);
			for(int v:choose){
				d[v]=0;
				for(int i=1;i<=n;i++) d[i]=min(d[i],dis[i][v]);
			}
			sm=0;
			for(int i=1;i<=n;i++) sm=max(sm,d[i]);
			ans=min(ans,sm);
			return;
		}else return;
	}
	for(int i=w;i<=n-c+1;i++){
		choose.push_back(i);
		dfs1(c-1,i+1);
		choose.pop_back();
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	if(c<=6){
		while(t--){
			memset(dis,0,sizeof(dis));
			for(int i=1;i<=n;i++) dis[i][0]=dis[0][i]=-1,e[i].clear();
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v; cin>>u>>v;
				e[u].push_back(v),e[v].push_back(u);
			}
			for(int i=1;i<=n;i++){
				dis[i][i]=0;
				dfs(i,i,i);
			}
			ans=2e9;
			for(int i=1;i<=n-k+1;i++){
				choose.clear();
				choose.push_back(i);
				dfs1(k-1,i+1);
				choose.pop_back();
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
