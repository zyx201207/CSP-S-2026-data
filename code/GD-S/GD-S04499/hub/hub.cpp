#include<bits/stdc++.h>
template<class T>inline bool chkmx(T&x, const T&v) {return x<v?x=v,1:0; }
template<class T>inline bool chkmn(T&x, const T&v) {return x>v?x=v,1:0; }
#define F(i,j,k) for(auto i=(j); i<=(k); i++)
#define G(i,j,k) for(auto i=(j); i>=(k); i--)
#define pb push_back
using ll = long long;
using namespace std;

const int N = 1e6+5;

int n, k;
vector<int> e[N];

bool del[N];
int de[N], mx, id;
void dfs(int u, int fa) {
	de[u] = de[fa]+1;
	if(chkmx(mx, de[u])) id=u;
	for(int v:e[u]) if(v!=fa && !(del[u] && del[v])) dfs(v,u);
}
int gtl(int u) {
	mx=id=-1; dfs(u,0);
	int v=id;
	mx=id=-1; dfs(v,0);
	return de[id];
}
int cal() {
	int as=0;
	F(i,1,n) de[i]=0;
	F(i,1,n) if(!de[i]) chkmx(as, gtl(i)/2);
	return as;
}

void mian(int Ca) {
	cin>>n>>k;
	F(i,1,n) e[i].clear();
	F(i,1,n-1) {int u,v; cin>>u>>v, e[u].pb(v), e[v].pb(u); }
	if(k==2) {
		int as=n;
		F(u,1,n) for(int v:e[u]) {
			del[u]=del[v]=1;
			chkmn(as, cal());
			del[u]=del[v]=0;
		}
		cout<<as<<'\n';
		return ;
	}
	if(n<=10) {
		int as=n;
		F(S,1,(1<<n)-1) {
			int o=__builtin_popcount(S), c=0;
			if(o!=k) continue;
			F(u,1,n) for(int v:e[u]) if((S>>(u-1)&1) && (S>>(v-1)&1)) c++;
			if(o-c>2) continue;
//			cout<<((bitset<10>)S)<<'\n';
			int mx=0;
			F(u,1,n) {
				if(S>>(u-1)&1) continue;
				int mn=n;
				dfs(u,0);
				F(v,1,n) if(S>>(v-1)&1) chkmn(mn, de[v]-1);
				chkmx(mx, mn);
			}
			chkmn(as,mx);
		}
		cout<<as<<'\n';
		return ;
	}
	if(k==n) {cout<<0<<'\n'; return ; }
	cout<<0<<'\n';
}
/*
*/
int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int Ca=0, Ti=1; cin>>Ca>>Ti;
	F(_,1,Ti) mian(Ca);
	return 0;
}

