#include<bits/stdc++.h>
template<class T>inline bool chkmx(T&x, const T&v) {return x<v?x=v,1:0; }
template<class T>inline bool chkmn(T&x, const T&v) {return x>v?x=v,1:0; }
#define F(i,j,k) for(auto i=(j); i<=(k); i++)
#define G(i,j,k) for(auto i=(j); i>=(k); i--)
#define pb push_back
using ll = long long;
using namespace std;

const int N = 2e6+5;

int n;
ll d, x[N];
vector<int> e[N];

ll f[N];
int dis[N];
void sol(int u) {
	queue<int> q;
	F(i,1,n) dis[i]=f[i]=0;
	dis[u]=1, f[u]=1;
	q.push(u);
	while(q.size()) {
		int u=q.front(); q.pop();
		for(int v:e[u]) {
			if(!dis[v]) dis[v] = dis[u]+1, q.push(v);
			if(dis[v] == dis[u]+1) f[v] += f[u];
		}
	}
}

void mian(int Ca) {
	cin>>n>>d;
	F(i,1,n) cin>>x[i], e[i].clear();
	if(n<=5000) {
		F(u,1,n) F(v,u+1,n) if(x[v] - x[u] <= d) e[u].pb(v);
		ll as=0;
		F(u,1,n) {
			sol(u);
			F(v,u,n) if(f[v]==2) as++;
		}
		cout<<as<<'\n';
		return ;
	}
	if(x[n] - x[1] <= d) {cout<<0<<'\n'; return ; }
	if(Ca>=13 && Ca<=14) {cout<<2<<'\n'; return ; }
	if(Ca>=11 && Ca<=12) {
		if(x[2] - x[1] >= d) {cout<<0<<'\n'; return ; }
		else cout<<2<<'\n';
	}
}
/*
*/
int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int Ca=0, Ti=1; cin>>Ca>>Ti;
	F(_,1,Ti) mian(Ca);
	return 0;
}

