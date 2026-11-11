#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
//µØÌúÕ¾Õ¾Ìü±àºÅ 1~m 
//Õ¾Ì¨±àºÅ  m+1 ~ m+d*m
long long port_id;
long long c,n,m,d,q;
long long w[N],dist[N];
bool vis[N];
vector<pair<long long,long long>> mapp[N];

long long dij(long long start,long long end);
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	port_id=m;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}	
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		long long last_port=-1;
		while(k--){
			long long subway,cost;//µØÌúÕ¾±àºÅºÍ»¨·Ñ 
			cin>>subway>>cost;
			port_id++;
			mapp[port_id].push_back({cost,subway}); 
			mapp[subway].push_back({cost,port_id}); 
			if(last_port!=-1){
				mapp[port_id].push_back({0,last_port});
				mapp[last_port].push_back({0,port_id});
			}
			last_port=port_id;
		}
	}
	while(q--){
		memset(dist,-1,sizeof(dist));
		memset(vis,0,sizeof vis);
		long long x,y;
		cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<endl;
	}
	return 0;
}
long long dij(long long x,long long y){
	using P=pair<long long,long long>;
	priority_queue<P,vector<P>,greater<P>> pq;
	pq.push({0,x});
	dist[x]=0;
	while(!pq.empty()){
		P now=pq.top();
		long long cost_d=now.first;
		long long s=now.second;
		pq.pop();
		if(vis[s])continue;
		vis[s]=1;
		for(P nxt : mapp[s]){
			long long cost=nxt.first;
			long long to=nxt.second;
			if(vis[to]==0 && (dist[to]==-1 || cost+cost_d<dist[to])){
				dist[to]=cost+cost_d;
				pq.push({dist[to],to});
				if(to==y)return dist[to];
			}
		}
	}
	return dist[y];
	
	
}
