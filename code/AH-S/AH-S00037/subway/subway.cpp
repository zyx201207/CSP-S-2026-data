#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>>e[200010];
long long c,m,n,cc,q,a[200010],d[200010],p[200010];
void dij(int s){
	priority_queue<pair<long long,long long>>pq;
	pq.push({s,0});
	memset(d,0x3f,sizeof d);
	d[s]=0;
	while(!pq.empty()){
		int u=pq.top().first;
		pq.pop();
		for(auto x:e[u]){
			int v=x.first,w=x.second;
			if(d[u]+w+p[u]<=d[v]){
				d[v]=d[u]+w+p[u];
				pq.push({v,-d[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>cc>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		long long t;
		cin>>t;
		for(int j=1;j<=t;j++){
			long long x,w;
			cin>>x>>w;
			if(i!=x){
				e[i].push_back({x,w});
				e[x].push_back({i,w});
			}
			else p[i]=w;
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		dij(s);
		cout<<d[t]+a[s]+a[t]<<"\n";
	}
	return 0;
}
