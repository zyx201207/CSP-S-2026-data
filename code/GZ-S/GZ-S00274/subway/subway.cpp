//GZ-S00274 贵阳市云岩区中天中学 张颜淏
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e6+10,INF=0x3f3f3f3f3f3f3f3f;

ll c,n,m,d,Q;
ll a[N];
ll wi[N];
bool vis[N];
ll dis[N];
ll x,y;

struct Edge{
	ll v;
	ll w;
};
vector<Edge> g[N];
queue<ll>q;

void spfa(ll st){
	memset(dis,0x3f,sizeof dis);
	dis[st]=0;
	vis[st]=1;
	q.push(st);
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		for(auto e:g[u]){
			if(dis[u]+e.w<=dis[e.v]){
				dis[e.v]=dis[u]+e.w;
				if(!vis[e.v]){
					q.push(e.v);
					vis[e.v]=1;
				}
			} 
		}
		vis[u]=0;
	}
	
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++){
		cin>>wi[i];
	}
	ll v,w;
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		for(ll j=1;j<=x;j++){
			cin>>v>>w;
			g[v].push_back({m+i,w});
			g[m+i].push_back({v,w});
		}
	}
	for(ll i=1;i<=Q;i++){
		cin>>x>>y;
		spfa(x);
		cout<<dis[y]+wi[x]+wi[y]<<"\n";
	}
	
	
    return 0;
}
