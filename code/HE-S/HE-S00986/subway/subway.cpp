#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
using namespace std;
const int N=5e5+5;
int dist[N];
bool vis[N];
int c,n,m,d,q;
int w[N];
vector<vector<pr> >ve(2527525);
const int inf=1e18;
void dijkstra(int s){
	priority_queue<pr,vector<pr>,greater<pr> >q;
	q.push({0,s});
	vis[s]=1;
	dist[s]=0;
	while(!q.empty()){
		pr cur=q.top();
		q.pop();
		int u=cur.second;
		for(int i=0;i<ve[u].size();i++){
			int v=ve[u][i].second;
			int w=ve[u][i].first;
			if(dist[v]>dist[u]+w&&!vis[v]){
				dist[v]=dist[u]+w;
				q.push({w,v});
				vis[v]=1;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			ve[i+500005].push_back({w,v});
			ve[v].push_back({w,i+500005});
		}
	}
	while(q--){
		for(int i=1;i<=N;i++){
			dist[i]=inf;
			vis[i]=0;
		}
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dist[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
