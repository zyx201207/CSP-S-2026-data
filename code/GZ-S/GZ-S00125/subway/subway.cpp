//GZ-S00125 曹讯 贵阳市第一中学
//subway
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500050];
vector <pair<int ,int> > kyh[500050];
int dist[500050];
bool vis[500050];
void dij(int s){
	dist[s]=0;
	vis[s]=1;
	priority_queue<pair<int ,int>, vector <pair<int ,int> >,greater<pair<int ,int> > > pq;
	pq.push({0,s});
	while(!pq.empty()){
		int a = pq.top().second;
		for(int i=1;i<=kyh[a].size();i++){
			int u=kyh[a][i].first;
			int v=kyh[a][i].second;
			pq.pop();
			if(vis[u]){
				continue;
			}
			if(dist[u]>dist[a]+v){
				dist[u]=dist[a]+v;
				pq.push({dist[u],u});
			}
			vis[u]=1;
			vis[a]=1;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,his;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			kyh[k+1+i].push_back({x,y});
			kyh[x].push_back({k+1+i,y});
			if(j!=1){
				 kyh[x].push_back({his,0});
				 kyh[his].push_back({x,0});
			}
			his=j;
		}
	}
	while(q--){
		memset(dist,INT_MAX,sizeof(n));
		memset(vis,0,sizeof(n));
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans+=w[x]+w[y];
		dij(x);
		cout<<dist[y]+ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

