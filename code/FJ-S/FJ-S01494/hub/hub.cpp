#include<bits/stdc++.h>
#define F(i,a,b) for ( int i=a; i<=b; i++)
#define FF(i,a,b) for ( int i=a; i>=b; i--)
#define lb(x) ( x & -x)
#define lp ( p <<1)
#define rp ( p <<1 |1)
#define mem(a,b) memset( a,b,sizeof(a))
#define emb emplace_back
using ll =long long;
using ull =unsigned long long;
using db =double;
using ldb =long double;
const int MAXN =1e6+5,INF =1e9;

using namespace std;
struct Edge{
	int u,v;
}e[MAXN];
int n,k,ans,dep[MAXN],lca[22][MAXN],col[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];

void dfs( int pos,int fa) {
	dep[pos] =dep[fa] +1,lca[0][pos] =fa;
	F ( i,1,20) F ( j,1,n) lca[i][pos] =lca[i-1][lca[i-1][pos]];
	for ( auto to:G[pos]) {
		if ( to ==fa) continue;
		dfs( to,pos);
	}
}

int get( int u,int v) {
//	cout <<u <<' ' <<v <<" -> ";
	if ( dep[u] <dep[v]) swap( u,v);
	while ( dep[u] !=dep[v]) u =lca[0][u];
//	cout <<u <<' ' <<v <<'\n';	
	if ( u ==v) return u;
	FF ( i,20,1) {
		if ( lca[i][u] !=lca[i][v])
			u =lca[i][u],v =lca[i][v];
	}
	return lca[0][u];
}

bool check() {
	int cnt =0;
	F ( i,1,n -1) {
		if ( vis[e[i].u] && vis[e[i].v]) ++cnt;
	}
	return ( cnt >=k-2 ? 1:0);
}

int calc() {
//	F ( i,1,n) cout <<vis[i];
//	cout <<'\n';
	int res =0;
	F ( i,1,n) {
		if ( vis[i]) continue;
		int tmp =INF;
		F ( j,1,n) {
			if ( !vis[j]) continue;
			int fa =get( i,j);
//			cout <<i <<' ' <<j <<" fa: " <<fa <<' ' <<" dis: " <<dep[i] +dep[j] -dep[fa] *2 <<'\n';
			tmp =min( tmp,dep[i] +dep[j] -dep[fa] *2);
		}
//		cout <<tmp <<' ';
		res =max( res,tmp);
	}
//	cout <<res <<'\n';
	return res;
}

void solve() {
	cin >>n >>k;
	mem( dep,0);
	F ( i,0,20) F ( j,1,n) lca[i][j] =0;
	F ( i,1,n) G[i].clear();
	F ( i,1,n -1) {
		int u,v; cin >>u >>v;
		e[i] ={ u,v};
		G[u].emb( v),G[v].emb( u);
	} 
	ans =INF;
	dfs( 1,0);
	F ( i,0,( 1 <<n) -1) {
		int x =i,cnt =0;
		while ( x) cnt +=( x &1),x >>=1;
		if ( cnt !=k) continue;
		int p =1; x =i;
		F ( i,1,n) vis[i] =0;
		while ( x) vis[p++] =( x &1),x >>=1;
		if ( !check()) continue;
		ans =min( ans,calc());
	}
	cout <<ans <<'\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	int T,c; cin >>c >>T;
	while ( T --) solve();


	return 0;
}
/****
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
****/

