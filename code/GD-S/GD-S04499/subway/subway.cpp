#include<bits/stdc++.h>
template<class T>inline bool chkmx(T&x, const T&v) {return x<v?x=v,1:0; }
template<class T>inline bool chkmn(T&x, const T&v) {return x>v?x=v,1:0; }
#define F(i,j,k) for(auto i=(j); i<=(k); i++)
#define G(i,j,k) for(auto i=(j); i>=(k); i--)
#define pb push_back
using ll = long long;
using namespace std;

const int N = 505, M = 5e5+5, T = N+M;
const ll Inf = 1e18;

int n, m, d, q;
int w[M];
vector<array<ll,2>> e[T];
ll mn[N][N];

void mian(int Ca) {
	cin>>n>>m>>d>>q;
	F(i,1,m) cin>>w[i];
	F(u,1,n) {
		int k; cin>>k;
		F(i,1,k) {int v,w; cin>>v>>w; e[v+n].pb({u,w}); }
	}
	memset(mn, 0x3f, sizeof mn);
	F(i,1,n) mn[i][i]=0;
	F(i,1,m) {
		int u=i+n;
		for(auto &x:e[u])
		for(auto &y:e[u]) chkmn(mn[x[0]][y[0]], x[1] + y[1]);
	}
	F(k,1,n) F(i,1,n) F(j,1,n) chkmn(mn[i][j], mn[i][k] + mn[k][j]);
//	F(i,1,n) {
//		F(j,1,n) cout<<mn[i][j]<<' ';
//		cout<<'\n';
//	}
	F(i,1,q) {
		int u,v; cin>>u>>v;
		ll as=Inf;
		for(auto &x:e[u+n])
		for(auto &y:e[v+n]) chkmn(as, x[1] + y[1] + mn[x[0]][y[0]] + w[u] + w[v]);
		cout<<as<<'\n';
	}
}
/*
*/
int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int Ca=0, Ti=1; cin>>Ca;
	F(_,1,Ti) mian(Ca);
	return 0;
}

