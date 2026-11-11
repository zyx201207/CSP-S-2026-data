#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500510;
const int M=5e5+10;
const ll INF=1e18;
ll c,n,m,dd,qq;
ll tot;
ll zt[N];
struct node{
	ll v;
	ll w;
};
vector<node>e[N];
struct edge{
	ll id,y;
};
vector<edge>qu[N];
vector<ll>ss;
bool vis[N];
ll ans[M];
bool mk[N];
ll d[N];
struct node2{
	ll id;
	ll dis;
	bool operator<(const node2& x)const{
		return dis>x.dis;
	}
};
priority_queue<node2>q;
void dijkstra(ll s){
	for(int i=1;i<=tot;i++)mk[i]=0;
	for(int i=1;i<=tot;i++)d[i]=INF;
	while(q.size())q.pop();
	d[s]=0;
	q.push({s,0});
	while(q.size()){
		ll u=q.top().id;
		ll dis=q.top().dis;
		q.pop();
		if(mk[u])continue;
		mk[u]=1;
		for(int i=0;i<e[u].size();i++){
			ll v=e[u][i].v;
			ll w=e[u][i].w;
			if(dis+w<d[v]){
				d[v]=dis+w;
				q.push({v,d[v]});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>qq;
	tot=m;
	for(int i=1;i<=m;i++)cin>>zt[i];
	for(int i=1;i<=n;i++){
		ll cnt;
		cin>>cnt;
		ll xl=++tot;
		for(int j=1;j<=cnt;j++){
			ll a,t;
			cin>>a>>t;
			e[a].push_back({xl,t});
			e[xl].push_back({a,t});
		}
	}
//	for(int i=1;i<=tot;i++){
//		for(int j=0;j<e[i].size();j++){
//			cout<<i<<" "<<e[i][j].v<<" "<<e[i][j].w<<"\n";
//		}
//	}
	for(int i=1;i<=qq;i++){
		ll x,y;
		cin>>x>>y;
		qu[x].push_back({i,y});
		if(!vis[x])ss.push_back(x),vis[x]=1;
	}
//	for(auto s:ss){
//		cout<<s<<"\n";
//		for(auto f:qu[s]){
//			cout<<s<<" "<<f.y<<"\n";
//		}
//	}
	for(auto s:ss){
		dijkstra(s);
		for(auto f:qu[s]){
			ll y=f.y;
			ll id=f.id;
			ans[id]=zt[s]+zt[y]+d[y];
		}
	}
	for(int i=1;i<=qq;i++)cout<<ans[i]<<"\n";
	return 0;
}
/*
c n m d  q
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
