#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=205;
const ll M=405;
const ll inf=1e18;
ll c,n,m,d,Q,a[M],dis[N*M];bool vis[N*M];
struct node{ll v,w;friend bool operator<(node x,node y){return x.w>y.w;}};
vector<node> G[N*M];priority_queue<node> q;
void add(ll u,ll v,ll w){G[u].push_back({v,w}),G[v].push_back({u,w});}
void dij(ll s){
	for(ll i=1;i<=(n+2)*m;i++) dis[i]=inf,vis[i]=0;
	dis[s]=0,q.push({s,dis[s]});
	while(!q.empty()){
		ll u=q.top().v;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto p:G[u]){
			ll v=p.v,w=p.w;
			if(dis[v]>dis[u]+w) dis[v]=dis[u]+w,q.push({v,dis[v]});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++){
		cin>>a[i];add((n+1)*m+i,n*m+i,a[i]);
//		cout<<n*m+i<<" "<<(n+1)*m+i<<endl;
	}
	for(ll i=1;i<=n;i++){
		ll x;cin>>x;ll lasx=0;
		for(ll j=1;j<=x;j++){
			ll x,y;cin>>x>>y;
			add((i-1)*m+x,n*m+x,y);
//			cout<<(i-1)*m+x<<" "<<n*m+x<<endl;
			if(lasx) add(lasx,(i-1)*m+x,0);
			lasx=(i-1)*m+x;
		}
	}
	while(Q--){
		ll u,v;cin>>u>>v;
		dij(u+(n+1)*m);
//		for(ll i=1;i<=(n+1)*m;i++) cout<<dis[i]<<" ";
//		cout<<endl;
		cout<<dis[v+(n+1)*m]<<endl;
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

*/
