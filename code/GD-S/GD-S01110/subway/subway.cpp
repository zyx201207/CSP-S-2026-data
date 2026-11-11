#include<bits/stdc++.h>
#define ll long long
#define N 1000000
using namespace std;
ll c,n,m,d,q,w[1010000],k,t,x,y,a,dis[N],vis[N];
struct Edge{
	ll v,w;
	bool operator<(const Edge& u)const{
		return w>u.w;
	}
};
vector<Edge>edge[N];
void dj(ll start){
	for(ll i=1;i<=n+m;i++)dis[i]=1e17,vis[i]=0;
	priority_queue<Edge>q;
	q.push({start,0});
	vis[start]=1;
	dis[start]=0;
	while(q.empty()==0){
		int u=q.top().v;
		vis[u]=1;
		q.pop();
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].v,w=edge[u][i].w;
			if(vis[v]==0&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>a>>t;
			edge[m+i].push_back({a,t});
			edge[a].push_back({m+i,t});
		}
	}
	while(q--){
		ll ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		dj(x);
		ans+=dis[y];
		cout<<ans<<'\n';
	} 
	return 0;
}
