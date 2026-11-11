#include<bits/stdc++.h>
#define int long long
#define P pair<int,int>
using namespace std;
int n,k,m,c,D,q,w[505],d[505];
vector<P>adj[505];
void dijkstra(int k){
	memset(d,0x3f,sizeof(d));
	d[k]=0;
	priority_queue<P,vector<P>,greater<P> >q;
	q.push({0,k});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(P o:adj[u]){
			int v=o.first,w=o.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		int aa,a,t,tt;
		if(k==2){
			cin>>a>>t>>aa>>tt;
			adj[a].push_back({aa,t+tt});
			adj[aa].push_back({a,t+tt});
		}else
			cin>>a>>a;
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		dijkstra(st);
		cout<<d[ed]+w[st]+w[ed]<<"\n";
	}
	return 0;
}
