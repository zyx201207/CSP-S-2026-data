#include<bits/stdc++.h>
using namespace std;
const long long maxn = 1e4 + 1540 , inf = 1e15;
long long c,n,m,d,q,dis[maxn],a[maxn],t[maxn],cnt[maxn];
vector<pair<long long,long long> > edge[maxn];
inline void Dijkstra(int s,int t){
	for(int i=1;i<=m*(d+3);++i) dis[i]=inf;
	dis[s]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
	q.push({0,s});
	while(!q.empty()){
		long long du=q.top().first,u=q.top().second;
		q.pop();
		if(du!=dis[u]) continue ;
		for(auto pii : edge[u]){
			int v=pii.first;
			long long w=pii.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	if(c<=8){
		for(int i=1,w;i<=m;++i){
			cin>>w;
			edge[i+(d+2)*m].emplace_back(i,w);
			edge[i].emplace_back(i+(d+2)*m,w); 
		}
		for(int i=1;i<=m;++i) cnt[i]=1;
		for(int i=1,k;i<=n;++i){
			cin>>k;
			for(int j=1;j<=k;++j) cin>>a[j]>>t[j],cnt[a[j]]++;
			edge[a[1]].emplace_back(a[1]+cnt[a[1]]*m,t[1]);
			edge[a[1]+cnt[a[1]]*m].emplace_back(a[1],t[1]);
			for(int j=2;j<=k;++j){
				edge[a[j]+cnt[a[j]]*m].emplace_back(a[j-1]+cnt[a[j-1]]*m,0);
				edge[a[j-1]+cnt[a[j-1]]*m].emplace_back(a[j]+cnt[a[j]]*m,0);
				edge[a[j]].emplace_back(a[j]+cnt[a[j]]*m,t[j]);
				edge[a[j]+cnt[a[j]]*m].emplace_back(a[j],t[j]);
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			Dijkstra(x+(d+2)*m,y+(d+2)*m);
			cout<<dis[y+(d+2)*m]<<'\n';
		}
	}
}
