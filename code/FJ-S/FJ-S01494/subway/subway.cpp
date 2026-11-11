#include<bits/stdc++.h>
#define F(i,a,b) for ( int i=a; i<=b; i++)
#define FF(i,a,b) for ( int i=a; i>=b; i--)
#define lb(x) ( x & -x)
#define PR pair<int,int>
#define lp ( p <<1)
#define rp ( p <<1 |1)
#define mem(a,b) memset(a,b,sizeof(a))
#define emb emplace_back
using ll =long long;
using ull =unsigned long long;
using db =double;
using ldb =long double;
const int MAXM =5e5+5,MAXN =605;
const ll INF =1e16;

using namespace std;
struct Node{
	int k;
	vector<PR> e;
}a[MAXN];
struct Edge{
	int to;
	ll w;
	bool operator <( const Edge &a) const{
		return a.w <w;
	}
};
vector<Edge> G[MAXM];
vector<int> h[MAXM];
int c,n,m,d,q;
ll w[MAXM],dis[MAXM],V;
bool vis[MAXM];

void dij( int s,int t) {
	F ( i,1,n +m) dis[i] =INF;	
	dis[s] =0,mem( vis,0);
	priority_queue<Edge> q; 
	q.push( {s,0});
	while ( q.size()) {
		int pos =q.top().to; q.pop();
		if ( vis[pos]) continue; vis[pos] =1;
		for ( auto i:G[pos]) {
			int to =i.to,wei =i.w;
//			cout <<pos <<"->" <<to <<' ' <<wei <<'\n';
			if ( dis[to] >dis[pos] +wei) {
				dis[to] =dis[pos] +wei;
				q.push( {to,dis[to]});
			}
		}
	}
	cout <<dis[t] +w[s] +w[t] <<'\n';
}

void solve() {
	cin >>c >>n >>m >>d >>q;
	F ( i,1,m) cin >>w[i];
	F ( i,1,n) {
		cin >>a[i].k;
		F ( j,1,a[i].k) {
			int to; ll v; cin >>to >>v;
			V =v;
			h[to].emb( i);
			a[i].e.push_back( {to,v});
			G[m +i].push_back( {to,v});
			G[to].push_back( {m+i,v}); 
		}
	}	
	while ( q--) {
		int x,y; cin >>x >>y;
		dij( x,y);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	solve();


	return 0;
}
/****

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

0 5 
****/
