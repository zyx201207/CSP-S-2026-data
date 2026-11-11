#include<bits/stdc++.h>
using namespace std;
const int N=5e5+600;
typedef long long ll;
struct d{
	int v;
	long long w;
	friend bool operator <(d a,d b){
		return a.w>b.w;
	}
};
priority_queue<d>q;
vector<d>e[N];
ll dis[N],w[N];
bool vis[N];
int n,m,D,c,Q;
void dij(int st,int ed){
	for(int i=1;i<=(m+n+1);++i)vis[i]=0,dis[i]=1e18;
	q.push({st,0});
	dis[st]=0;
	while(q.size()){
		int u=q.top().v;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto y:e[u]){
			ll W=y.w;
			int v=y.v;
			if(dis[v]>dis[u]+W){
				dis[v]=dis[u]+W;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>D>>Q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;++i){
		cin>>k;
		for(int j=1,a;j<=k;++j){
			ll t;
			cin>>a>>t;
			e[i+m].push_back({a,t});
			e[a].push_back({i+m,t});
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		
//		if(p[x][y]){
//			cout<<p[x][y]+w[x]+w[y]<<"\n";
//			continue;
//		}
		dij(x,y);
//		for(int i=1;i<=n;++i){
//			if(i!=x){
//				p[i][x]=dis[i];
//				p[x][i]=dis[i];
//			}
//		}
		cout<<dis[y]+w[y]+w[x]<<"\n";
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
