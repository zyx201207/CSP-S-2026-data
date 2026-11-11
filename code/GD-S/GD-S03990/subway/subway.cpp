#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
struct node{
	int v,w;
};
int c,n,m,d,q;
int w[N],dis[N+550];
vector<node>e[N+550];
priority_queue<pair<int,int>>pq;
void dij(int st){
	pq.push({0,st});
	dis[st]=0;
	while(pq.size()){
		int u=pq.top().second;
		pq.pop();
		for(auto x:e[u]){
			int v=x.v,w=x.w;
			if(dis[v]!=-1)continue;
			dis[v]=dis[u]+w;
			pq.push({-dis[v],v});
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k,v,w;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			e[i+m].push_back({v,w});
			e[v].push_back({i+m,w});
		}
		
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		memset(dis,-1,sizeof dis);
		dij(st);
		cout<<dis[ed]+w[st]+w[ed]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
