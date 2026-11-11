#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+10,M=505;
ll C,n,m,D,Q,w[N],d[N][N],vis[N];
struct node{
	ll v,w;
	bool operator<(const node &x)const{
		return w>x.w;
	}
};
vector<node> g[N];
void djk(ll s){
	priority_queue<node> q;
	q.push({s,0});
	memset(vis,0,sizeof vis);
	vis[s]=1;
	while(!q.empty()){
		auto [u,uw]=q.top(); q.pop();
		for(auto [v,w]:g[u]){
			if(vis[v]) continue;
			vis[v]=1;
			d[v][s]=d[s][v]=min(d[s][v],uw+w);
			q.push({v,d[s][v]});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>Q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k; cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t; cin>>a>>t;
			g[m+i].push_back({a,t});
			g[a].push_back({m+i,t});
		}
	}
	for(ll i=1;i<=m+n;i++) for(ll j=1;j<=m+n;j++) d[i][j]=(i==j?0:1e9);
	for(ll i=m+1;i<=m+n;i++) djk(i);
	while(Q--){
		ll x,y,res=1e9; cin>>x>>y;
		for(auto [xv,xw]:g[x]){
			for(auto [yv,yw]:g[y]){
				res=min(res,d[xv][yv]+w[x]+w[y]+d[x][xv]+d[y][yv]);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}

