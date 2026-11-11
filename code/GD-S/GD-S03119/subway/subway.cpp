#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=500005;
const int Q=100005;
vector<pair<long long,long long> >g[2*M+N];
long long x,y,ans[Q],w[M];
long long c,n,m,d,q,k,a,t;
long long dist[2*M+N];
deque<int>dq;
long long solve(int x,int y){
	int u,v;
	long long p;
	memset(dist,0x3f,sizeof(dist));
	dq.clear();
	dist[x]=0;
	dq.push_back(x);
	while(!dq.empty()){
		u=dq.front();
		dq.pop_front();
		for(auto it:g[u]){
			v=it.first;
			if(dist[u]+it.second<dist[v]){
				dist[v]=dist[u]+it.second;
				if(dist[v]<=dist[dq.front()]){
					dq.push_front(v);
				}
				else{
					dq.push_back(v);
				}
			}
		}
	}
	return dist[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
		g[i].push_back({m+i,w[i]});
		g[m+i].push_back({i,w[i]});
	}
	for(int i=1; i<=n; i++){
		cin>>k;
		for(int j=1; j<=k; j++){
			cin>>a>>t;
			g[2*m+i].push_back({m+a,t});
			g[m+a].push_back({2*m+i,t});
		}
	}
	for(int i=1; i<=q; i++){
		cin>>x>>y;
		ans[i]=solve(x,y);
	}
	for(int i=1; i<=q; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

