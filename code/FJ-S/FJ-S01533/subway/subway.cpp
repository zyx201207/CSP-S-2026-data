#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fi first
#define se second

const int N=505;
const int M=5e5+5;
const int Q=1e5+5;
const ll INF=0x3f3f3f3f3f3f3f3fLL;
int c,n,m,d,q,ks[N];
ll W[M];

void solveA(){
	static vector<pair<int,ll>>G[N];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		if(k==1){
			cin>>k>>k;
			continue;
		}
		int u,v;
		ll t1,t2;
		cin>>u>>t1>>v>>t2;
		G[u].push_back({v,t1+t2});
		G[v].push_back({u,t1+t2});
	}
	static ll dist[N];
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		memset(dist,0x3f,sizeof dist);
		priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
		pq.push({0,x});
		dist[x]=0;
		while(!pq.empty()){
			int u=pq.top().se;
			ll w=pq.top().fi;
			pq.pop();
			for(auto &ele:G[u]){
				int v=ele.fi;
				ll ww=ele.se;
				if(w+ww<dist[v]){
					dist[v]=w+ww;
					pq.push({dist[v],v});
				}
			}
		}
		cout<<dist[y]+W[x]+W[y]<<'\n';
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>W[i];
	if(c>=7&&c<=11){
		solveA();
		return 0;
	}
	static vector<pair<int,ll>>x[M];
	static pair<int,int>qs[Q];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			x[a].push_back({i,t});
		}
	}
	for(int i=1;i<=q;i++)cin>>qs[i].fi>>qs[i].se;
	
	return 0;
}
