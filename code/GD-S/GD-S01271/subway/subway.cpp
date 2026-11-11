#include<bits/stdc++.h>
using namespace std;
const int N=5005;

using ll=long long;
ll a[N];
ll dis[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	vector<pair<int,int>> graph[N];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int u,t,v,t1;
			cin>>u>>t>>v>>t1;
			graph[u].push_back({v,t+t1});
			graph[v].push_back({u,t+t1});
		}
	}
	while(q--){
		int x,y;
		priority_queue<pair<int,int>>q;
		q.push({0,x});
		while(q.size()){
			dis[q.top().second]=abs(q.top().first);
			for(auto e:graph[q.top().second]){
				if(dis[e]){
					continue;
				}
				q.push({-(q.top.first+e.second),e});
			}
		}
		cout<<dis[y];
	}
	
} 
