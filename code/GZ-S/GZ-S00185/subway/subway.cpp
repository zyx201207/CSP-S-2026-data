#include<bits/stdc++.h>
#define pii pair<long long,long long>
#define ll long long
using namespace std;
const int N=1005;
ll c,n,m,d,q,dist[N][N],w[N];
vector< pii >g[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			g[a].push_back({i+m,t});
			g[i+m].push_back({a,t});
		}
	}
	for(int s=1;s<=m;s++){
		for(int t=1;t<=m+n;t++) dist[s][t]=1e18;
		priority_queue<pii,vector< pii >,greater< pii > >q;
		q.push({0,s});
		dist[s][s]=0;
		while(q.size()){
			int d=q.top().first,u=q.top().second;
			q.pop();
			if(d>dist[s][u]) continue;
			for(auto e:g[u]){
				int v=e.first,w=e.second;
				if(dist[s][u]+w<dist[s][v]){
					dist[s][v]=dist[s][u]+w;
					q.push({dist[s][v],v});
				}
			}
		}
	}
	while(q--){
		int s,t;cin>>s>>t;
		cout<<dist[s][t]+w[s]+w[t]<<'\n';
	}
	return 0;
} 
