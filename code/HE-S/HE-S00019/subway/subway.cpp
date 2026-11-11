#include <bits/stdc++.h>
using namespace std;
const long long N=500509;
struct Point{
	long long u,dist;
	operator<(const Point &p)const{
		return dist>p.dist;
	}
};
struct E{
	long long v;
	long long w;
};
long long c,n,m,d,q,w[N],x,y,ans,dist[N];
bool vis[N];
vector<E> G[N];
void work(long long x){
	fill(vis,vis+N+1,false);
	fill(dist,dist+N+1,0x3f3f3f3f);
	dist[x]=0;
	priority_queue<Point> pq;
	pq.push({x,dist[x]});
	while(pq.size()){
		long long u=pq.top().u;pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto e:G[u]){
			long long v=e.v,w=e.w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push({v,dist[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long u,w;
			cin>>u>>w;
			G[m+i].push_back({u,w});
			G[u].push_back({m+i,w});
		}
	}
	while(q--){
		cin>>x>>y;
		ans=0;
		ans=ans+w[x]+w[y];
		work(x);
		if(dist[y]!=0x3f3f3f3f)	ans+=dist[y]; 
		cout<<ans<<'\n';
	}
	return 0;
} 
