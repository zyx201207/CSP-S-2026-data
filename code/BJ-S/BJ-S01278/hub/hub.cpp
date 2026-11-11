#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
int c,t,n,k,dis[15][15];
vector<int> g[15];
bool b[15],visited[15];
void dfs(int x){
	visited[x]=true;
	for(int y:g[x]){
		if(!visited[y]&&b[y]) dfs(y);
	}
}
void cal(){
	for(int i=1;i<=n;i++){
		queue<int> q;
		q.push(i);
		for(int j=1;j<=n;j++) dis[i][j]=1e9;
		dis[i][i]=0;
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(int y:g[x]){
				if(dis[i][y]>dis[i][x]+1){
					dis[i][y]=dis[i][x]+1;
					q.push(y);
				}
			}
		}
	}
}
int main(){
	//freopen("/home/csps/Downloads/hub/hub2.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		
		cal();
		for(int i=0;i<(1<<n);i++){
			int c=0;
			for(int j=0;j<n;j++){
				b[j+1]=(i>>j)&1;
				c+=b[j+1];
			}
			if(c!=k) continue;
			int cnt=0;
			memset(visited,false,sizeof(visited));
			for(int j=1;j<=n;j++){
				if(b[j]&&!visited[j]) dfs(j),cnt++;
			}
			if(cnt>2) continue;
			int mx=0;
			for(int j=1;j<=n;j++){
				int mn=1e9;
				for(int p=1;p<=n;p++){
					if(b[p]) mn=min(mn,dis[j][p]);
				}
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
