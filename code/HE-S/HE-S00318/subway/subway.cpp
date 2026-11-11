#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N=510,M=5e5+10;
typedef pair<int,int>PII;
int w[M];
vector<PII>v[M],e[N];
int c,n,m,d,q;
int minn[N][N];
int dist[N][N],st[N][N];
void dijkstra(int s){
	priority_queue<PII,vector<PII>,greater<PII>>heap;
	heap.push({0,s});
	dist[s][s]=0;
	while(!heap.empty()){
		int u=heap.top().se;heap.pop();
		if(st[s][u])continue;
		st[s][u]=true;
		for(auto it:e[u]){
			int v=it.fi,w=it.se;
			if(dist[s][v]>dist[s][u]+w){
				dist[s][v]=dist[s][u]+w;
				heap.push({dist[s][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			v[a].push_back({t,i});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			minn[i][j]=1e18;
			dist[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto it1:v[i]){
			for(auto it2:v[i]){
				if(it1==it2)continue;
				minn[it1.se][it2.se]=minn[it2.se][it1.se]=min(minn[it1.se][it2.se],it1.fi+it2.fi);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(minn[i][j]!=1e18)e[i].push_back({j,minn[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		int ans=1e18;
		for(auto it1:v[x]){
			for(auto it2:v[y]){
				ans=min(ans,dist[it1.se][it2.se]+w[x]+w[y]+it1.fi+it2.fi);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
