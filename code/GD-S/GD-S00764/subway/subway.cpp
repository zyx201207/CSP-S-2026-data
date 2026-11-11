#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> state;
const ll N=5e5+1e3,M=510,inf=1e18;
vector<state>e[N];
ll c,n,m,d,q,x,y;
map<ll,ll>T[N];
vector<ll>trains[N];
ll w[N],k[N],dis[M][M];
bitset<N>vis;
priority_queue<state,vector<state>,greater<state> >pq;
void add(ll u,ll v,ll w){
	e[u].emplace_back(v,w);
	e[v].emplace_back(u,w);
}
void dij(ll s){
	for(ll i=1;i<=n;i++)dis[s][i]=inf,vis[i]=0;
	dis[s][s]=0;
	pq.emplace(dis[s][s],s);
	while(pq.size()){
		ll u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto k:e[u]){
			ll v=k.first,w=k.second;
			if(vis[v])continue;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				pq.emplace(dis[s][v],v);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1,cur;j<=k[i];j++){
			cin>>x>>cur;
			T[x][i]=cur;
			trains[x].emplace_back(i);
		}
	}
	for(ll i=1;i<=m;i++)
		for(ll j:trains[i])
			for(ll k:trains[i])
				if(j!=k)add(j,k,T[i][j]+T[i][k]);
	for(ll i=1;i<=n;i++)dij(i);
	while(q--){
		cin>>x>>y;
		if(x==y){
			cout<<"0\n";
			continue;
		}
		ll mi=inf;
		for(ll i:trains[x])
			for(ll j:trains[y])
				mi=min(mi,T[x][i]+T[y][j]+dis[i][j]);
		cout<<mi+w[x]+w[y]<<"\n";
	}
	return 0;
} /*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
-----------------
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/
