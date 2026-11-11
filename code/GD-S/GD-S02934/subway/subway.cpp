#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+5,M=5e5+5;
const ll inf=1e18;
int c,n,m,k,d,Q,u,v,w;
int a[N];
ll dis[N][N];
struct node{
	int v,w;
};
vector<node>e[M],b[N];
priority_queue<pair<ll,int>>q;
void bfs(int U){
	q.push({0,U});dis[U][U]=0;
	while(!q.empty()){
		ll x=-q.top().first;
		int u=q.top().second;
		q.pop();
		if(dis[U][u]<x) continue;
		for(auto i:b[u]){
			int X=i.v,Y=i.w;
			for(auto j:e[X]){
				int v=j.v,w=j.w;
				if(dis[U][v]>x+w+Y){
					dis[U][v]=x+w+Y;
					q.push({-x-w-Y,v});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			e[i].push_back({v,w});
			b[v].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++) bfs(i);
	for(int i=1;i<=Q;i++){
		cin>>u>>v;
		cout<<dis[u][v]+a[u]+a[v]<<"\n";
	}
	return 0;
} 
