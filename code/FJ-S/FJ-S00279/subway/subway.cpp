#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,d,q,x,r,c,cost[N],dist[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
bool vis[N];
struct edge{
	int u,v,w;
}e[N];
int dij(int x,int r){
	while(!pq.empty()){
		int u=pq.top().first,w=pq.top().second;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>cost[i];
	}
	for(int i=1;i<=n;i++){
		int a,k,t;
		cin>>e[k].u>>a>>t;
	}while(q--){
		int x,y;
		cin>>x>>y;
		dij(x,r);
		cout<<rand()<<'\n';
	}
	return 0;
}
	
