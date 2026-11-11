#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,qq,w[500005],dis[505][505],dp[505][505];
bool vis[505];
pair<int,int> a[500005][21];
vector<pair<int,int> > g[505];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x][0].first++;
			a[x][a[x][0].first]={m+i,y};
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=a[i][0].first;j++){
			for(int k=j+1;k<=a[i][0].first;k++){
				dis[a[i][j].first-m][a[i][k].first-m]=min(dis[a[i][j].first-m][a[i][k].first-m],a[i][j].second+a[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]!=0x3f3f3f3f3f3f3f3f){
				g[i].push_back({j,dis[i][j]});
				g[j].push_back({i,dis[i][j]});
			}
		}
	}
	for(int s=1;s<=n;s++){
		q.push({0,s});
		for(int i=1;i<=n;i++)dp[s][i]=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++)vis[i]=false;
		dp[s][s]=0;
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u]=true;
			for(auto p:g[u]){
				int v=p.first,r=p.second;
				if(dp[s][v]>dp[s][u]+r){
					dp[s][v]=dp[s][u]+r;
					q.push({dp[s][v],v});
				}
			}
		}
	}
	while(qq--){
		int u,v;
		cin>>u>>v;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=a[u][0].first;i++){
			for(int j=1;j<=a[v][0].first;j++){
				ans=min(ans,dp[a[u][i].first-m][a[v][j].first-m]+a[u][i].second+a[v][j].second+w[u]+w[v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
