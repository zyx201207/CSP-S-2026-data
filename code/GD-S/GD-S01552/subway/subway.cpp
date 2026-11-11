#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const int M=124760;
const int N=510;
ll c,n,m,d,q;
ll w[M];
ll f[N+M],vis[N+M];
vector<pll>g[N];
void bfs(int s){
	queue<pll>q;
	memset(f,0x3f,sizeof(f));
	memset(vis,0,sizeof(vis));
	f[s]=0;
	q.push({0,s});
	while(!q.empty()){
		auto fr=q.front();
		ll u=fr.second,step=fr.first;
		q.pop();
		vis[u]=1;
		for(auto x:g[u]){
			ll v=x.first,ww=x.second;
			if(ww+step<f[v]){
				f[v]=ww+step;
				q.push({f[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1,k;i<=n;i++){
		cin>>k;
		for(ll j=1,a,t;j<=k;j++){
			cin>>a>>t;
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	for(ll i=1,u,v;i<=q;i++){
		cin>>u>>v;
		bfs(u);
		cout<<f[v]+w[u]+w[v]<<endl;
	}
	return 0;
}
