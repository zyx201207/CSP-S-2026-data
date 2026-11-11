#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
#define N 510
#define M 500010
#define inf 1000000000000000ll
int C,n,m,D,Q;
int W[M];
int K[N];
vector<PII>ve[M];
int dis[N][N];

vector<PII>G[N];
priority_queue<PII,vector<PII>,greater<PII>>q;
bool vis[N];
void bfs(int st){
	for(int i=1;i<=n;i++)dis[st][i]=inf;
	memset(vis,0,sizeof(vis));
	
	dis[st][st]=0;q.push({0,st});
	while(q.size()){
		PII _=q.top();q.pop();
		int x=_.second;
		if(vis[x])continue;
		vis[x]=1;
		for(auto i:G[x]){
			int y=i.fi,w=i.se;
			if(dis[st][y]>dis[st][x]+w){
				dis[st][y]=dis[st][x]+w;
				q.push({dis[st][y],y});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++){
		cin>>K[i];
		for(int j=1,x,t;j<=K[i];j++)cin>>x>>t,ve[x].push_back({i,t});
	}
	
	for(int i=1;i<=m;i++){
		for(int j=0;j<ve[i].size();j++){
			for(int k=j+1;k<ve[i].size();k++){
				int x=ve[i][j].fi,y=ve[i][k].fi,w=ve[i][j].se+ve[i][k].se;
				G[x].push_back({y,w});G[y].push_back({x,w});
			}
		}
	}
	
	for(int i=1;i<=n;i++)bfs(i);
	
	while(Q--){
		int st,ed;cin>>st>>ed;
		int ans=inf;
		
		for(int i=0;i<ve[st].size();i++){
			for(int j=0;j<ve[ed].size();j++){
				ans=min(ans,dis[ve[st][i].fi][ve[ed][j].fi]+ve[st][i].se+ve[ed][j].se);
			}
		}
		
		cout<<ans+W[st]+W[ed]<<'\n';
	}
	
	return 0;
}
