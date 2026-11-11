#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=510;
int c,n,m,d,q;
int w[N],a[N][N],t[N][N];
int dist[N*N];
vector<PII> g[N*N];
priority_queue<PII,vector<PII>,greater<PII>> p;
void dijkstra(int s){
	memset(dist,0x3f,sizeof dist);
	dist[s]=0;
	p.push({0,s});
	while(p.size()){
		int u=p.top().second;
		p.pop();
		for(int i=0;i<g[u].size();i++){
			int j=g[u][i].first,w=g[u][i].second;
			if(dist[j]>dist[u]+w){
				dist[j]=dist[u]+w;
				p.push({dist[j],j});
			}
		}
	}
}
signed main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
		for(int j=1;j<=k;j++){
			g[a[i][j]*(n+1)].push_back({a[i][j]*(n+1)+i,t[i][j]});
			g[a[i][j]*(n+1)+i].push_back({a[i][j]*(n+1),t[i][j]});
			g[a[i][j]*(n+1)+i].push_back({a[i][j+1]*(n+1)+i,0});
			g[a[i][j+1]*(n+1)+i].push_back({a[i][j]*(n+1)+i,0});
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		dijkstra(s*(n+1));
		cout<<dist[t*(n+1)]+w[s]+w[t]<<endl;
	}

	return 0;
}
