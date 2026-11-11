#include<bits/stdc++.h>
//#define int long long
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int,int>;
const int NX = 505;
const int MX = 500005 + 505;
struct Edge{
	int to,nxt;
	ll w;
}e[2*MX];
int hd[NX],cnt;
void Add(int u, int v, ll w){
	e[++cnt] = (Edge){v, hd[u], w};
	hd[u] = cnt;
}
int n,m,d;
ll wi[MX];
struct Node{
	int pos; ll dis;
	bool operator < (const Node &b)const{
		if(dis == b.dis) return pos > b.pos;
		return dis > b.dis;
	}
};
ll dis[MX];
bool vis[MX];
void Dijkstra(int S){
	memset(dis, 0x3f, (n+m+10)*sizeof (ll));
	memset(vis, 0, (n+m+10)*sizeof (bool)); 
	priority_queue<Node> q;
	dis[S] = 0;
	q.push({S,0});
	while(!q.empty()){
		Node cur;
		do{
			cur = q.top();
			q.pop();
		}while(vis[cur.pos] && !q.empty());
		vis[cur.pos] = 1;
		for(int j = hd[cur.pos]; j; j = e[j].nxt){
			if(dis[e[j].to] > dis[cur.pos] + e[j].w){
				dis[e[j].to] = dis[cur.pos] + e[j].w;
				q.push({e[j].to, dis[e[j].to]});
			}
		}
	}
}
//!!!!!!!!!!!!!!!!别忘了freopen!!!!!!!!!!!!!!!!!!!!!!! 
//struct AA{
//	int id,x,y;
//	bool operator < (const AA &a, const AA &b)const{
//		if(a.x == b.x) return a.y > b.y;
//		return a.x > b.x;
//	}
//};
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; ++i)
		cin>>wi[i];
	for(int k,i=1; i<=n; ++i){
		cin>>k;
		for(int a,t,j=1; j<=k; ++j){
			cin>>a>>t;
			Add(a, m+k, t);
			Add(m+k, a, t);
		}
	}
	vector<pii> asks;
	asks.reserve(q);
	vector<ll> ans(q, 0x3f3f3f3f3f3f3f3f);
	while(q--){
		int x,y;
		cin>>x,y;
		asks.push_back({x,y}); 
	}
	for(int i=1; i<=n; ++i){
		Dijkstra(m+i);
		for(int j=0; j<q; ++j)
			ans[j] = min(ans[j], dis[asks[i].first] + dis[asks[i].second]);
	}
	for(int i=0; i<q; ++i)
		cout<<ans[i]<<'\n';
//	vector<AA> asks(q);
//	vector<ll> ans(q);
//	vector<bool> vans(q,0);  	// 这个 q整的我没招了 
//	for(int x,y,i=0; i<q; ++i){
//		cin>>x>>y;
//		asks[i] = (AA){i,x,y}
//	}
//	sort(asks.begin() , asks.end());
//	for(int i=0; i<q; ++i){
//		if(!asks[i].x) Dijkstra(asks[i].x);
//		ans[asks[i].id] = wi[asks[i].x] + dis[asks[i].y] + wi[asks[i].y];
//	}
//	for(int i=0; i<q; ++i)
//		cout<<ans[i]<<'\n';
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


rp++
*/

