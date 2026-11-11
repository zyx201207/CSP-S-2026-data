#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+300;
const int inf=6e14;
int _,n,m,p,q;
int a[N];
int d[N];
//建立线路点，跑dij 
vector<pair<int,int>> g[N];
int dij(int s,int e){
	for(int i=1;i<=m+n+1;i++) if(d[i]!=inf) d[i]=inf;
	d[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,s});
	while(!pq.empty()){
		auto t=pq.top();
		int val=t.first,u=t.second;
		pq.pop();
		if(u==e) return d[u];
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				pq.push({w,v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>_>>n>>m>>p>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			g[i+m].push_back({x,t});
			g[x].push_back({i+m,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y)+a[x]+a[y]<<endl;
	}
} 
