#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,d,dist[N],a[N],b[N],degree[N],dp[N],c,t;
vector<pair<int,int>>g[N];
bool vis[N];
queue<int>q;
void spfa(int s){
	memset(dist,0x3f3f3f3f,sizeof dist);
	q.push(s);
	dist[s]=0;
	vis[s]=1;
	while(q.size()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(auto ed:g[u]){
			int v=ed.first,w=ed.second;
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+w;
				if(vis[v]==0){
					q.push(v);
					vis[v]=1;
				}
			} 
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;a[i]+d>=a[j]&&j<=n;j++){
				g[i].push_back({j,1});
				degree[j]++;
			}
		}
		spfa(1);
		queue<int>p;
		for(int i=1;i<=n;i++){
			if(degree[i]==0){
				p.push(i);
				dp[i]=1;
			}
		}
		while(p.size()){
			int u=p.front();p.pop();
			for(auto ed:g[u]){
				int v=ed.first;
				dp[v]+=dp[u];
				degree[v]--;
				if(degree[v]==0){
					p.push(v);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(dp[i]==2)ans++;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

