#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510;
const ll M=510;
const ll E=2*(20*N+M);
const ll V=2*M;
struct edge{
	ll ed,nxt,v;
}b[E];
struct node{
	ll x,dis; 
	bool operator < (const node&a) const{
		return dis<a.dis;
	}
	bool operator > (const node&a) const{
		return dis>a.dis;
	}
};
struct node2{
	ll id,t;
};
ll cid,n,m,d,Q,wal[M],st[N],nbs[V],tot,cnt,edg[M][N],e[M],dis[V];
vector<node2> g[M];
vector<ll> a[N];
priority_queue<node,vector<node>,greater<node> > q;
void add(ll x,ll y,ll z){
	b[++tot].ed=y; b[tot].nxt=nbs[x]; nbs[x]=tot;
	b[tot].v=z;
}
ll bfs(ll s,ll t){
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		node tmp=q.top(); q.pop();
		if(tmp.dis>dis[tmp.x]) continue;
		for(ll x=nbs[tmp.x];x;x=b[x].nxt){
			ll u=b[x].ed,v=b[x].v;
			if(dis[tmp.x]+v<dis[u]){
				dis[u]=dis[tmp.x]+v;
				q.push({u,dis[u]});
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cid>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++) cin>>wal[i];
	for(ll i=1;i<=n;i++){
		cin>>st[i];
		for(ll j=1,x,t;j<=st[i];j++){
			cin>>x>>t;
			a[i].push_back(x);
			g[x].push_back({i,t});
		}
	}
	for(ll i=1;i<=n;i++){
		ll s=a[i].size();
		edg[a[i][0]][i]=++cnt;
		for(ll j=1;j<s;j++){
			ll u=a[i][j];
			ll k=a[i][j-1];
			edg[u][i]=++cnt;
			add(edg[k][i],edg[u][i],0);
			add(edg[u][i],edg[k][i],0);
		}
	}
	for(ll i=1;i<=m;i++){
		ll s=g[i].size();
		e[i]=++cnt;
		for(ll j=0;j<s;j++){
			ll u=edg[i][g[i][j].id],t=g[i][j].t;
			add(e[i],u,t);
			add(u,e[i],t);
		}
	}
	while(Q--){
		ll x,y;
		cin>>x>>y;
		for(ll i=1;i<=cnt;i++) dis[i]=1e18;
		ll ans1=bfs(e[y],e[x])+wal[x]+wal[y];
		printf("%lld\n",ans1);
	}
	return 0;
}
