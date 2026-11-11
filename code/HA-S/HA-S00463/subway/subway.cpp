#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,n,m,d,q;
int w[N];
int p[N],t[N];
vector<pair<int,int> > g[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int dist[N];
void dijskra(int s){
	memset(dist,0x3f,sizeof dist);
	pq.push({0,s});
	dist[s]=0;
	while(!pq.empty()){
		int u=pq.top().second;
		int dis=pq.top().first;
		pq.pop();
		if(dis>dist[u]){
			continue;
		}
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first;
			int w=g[u][i].second;
//			cout<<v<<" "<<w<<endl;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		memset(p,0,sizeof p);
		memset(t,0,sizeof t);
		for(int j=1;j<=k;j++){
			cin>>p[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			g[i+m].push_back({p[j],t[j]});
			g[p[j]].push_back({i+m,t[j]});
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<g[i].size();j++){
//			cout<<g[i][j].first<<" "<<g[i][j].second<<"\n";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		dijskra(s);
		cout<<dist[t]+w[s]+w[t]<<"\n";
	}
	return 0;
}
//Ò»¶¨40tps
