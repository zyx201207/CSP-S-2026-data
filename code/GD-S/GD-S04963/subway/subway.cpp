#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII; 
const ll N=5e5+10,M=2e6+10,inf=0x7fffffff;
vector<PII> g[M]; 
ll c,n,m,d,q,w[510];
ll dis[N];
bool st[N];
ll dijkstra(int s,int t){
	priority_queue<PII,vector<PII>,greater<PII> > q;
	for(int i=0;i<N;i++) dis[i]=inf;
	memset(st,0,sizeof st);
	dis[s]=0;
	q.push({dis[s],s});
	while(q.size()){
		PII k=q.top();
		q.pop();
		ll v=k.second;
		if(st[v]) continue;
		st[v]=true;
		for(int i=0;i<g[v].size();i++){
			ll j=g[v][i].first,w=g[v][i].second;
			if(dis[j]>dis[v]+w){
				dis[j]=dis[v]+w;
				q.push({dis[j],j});
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k,lasta;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			g[a].push_back({i*m+a,t});
			g[i*m+a].push_back({a,t});
			if(j!=1){
				g[i*m+lasta].push_back({i*m+a,0});
				g[i*m+a].push_back({i*m+lasta,0});
			}
			lasta=a;
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dijkstra(u,v)+w[u]+w[v]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
