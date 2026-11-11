#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=5e5+5;
struct T{
	int n;
	int t;
};
vector<T> a[N];
int w[M];
int k[N];
vector<pair<int,int>> g[N];
int dist[M];
int 	
int c,n,m,d,q;
void bfs(int s,int e){
	queue<int>q;
	q.push_back(s);
	dist[s]=0;
	while(q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			dist[v]=min(dist[v],dist[u]+g[u]);
		} 
	}
}
int main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(7<=c&&c<=11){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int x,t;
				cin>>x>>t;
				a[i].push_back({x,t});
			}
			g[a[i][1].x].push_back({a[i][2].x,a[i][2].t});
			g[a[i][2].x].push_back({a[i][1].x,a[i][1].t});
		}
		while(q--){
			int s,e;
			cin>>s>>e;
			memset(dist,0,sizeof(dist));
			bfs(s,e); 
		} 
	}
	
	
	return 0;
}
 
