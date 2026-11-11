#include<bits/stdc++.h>
#define E emplace_back
using namespace std;

const int M = 4005;
int _c , T , n , k , d , fr[M] , fa[M] , anc[M] , r1 , r2 , dz;
vector<int> to[M] , s[M];
bitset<M> vs , st , rm;
queue<int> q;

int md[M] , f[M] , dg[M] , c[M];
void dfs2(int u){
	md[u] = 1 , f[u] = 0;
	for(int v : s[u]) dfs2(v) , md[u] = max(md[u] , md[v] + 1) , f[u] += f[v];
	if(md[u] > d) ++f[u];
}
void dfs3(int u){ vs[u] = 1; for(int v : s[u]) dfs3(v); }
void dfs4(int u , int f , int l){
	if(!l) return ;
	st[u] = 1;
	for(int v : to[u]) if(v != f) dfs4(v , u , l - 1);
}

bool solve(int u , int w){
	vs.reset() , st.reset() , rm.reset() , memset(dg , 0 , sizeof(dg));
	dfs3(u);
	for(int i = 1; i <= n; ++i) if(!vs[i])
		for(int j : to[i]) if(!vs[j]) ++dg[i];
	dfs4(fa[u] , u , d);
	for(int i = 1; i <= n; ++i) if(st[i] && dg[i] <= 1) rm[i] = 1 , q.push(i);
	// if(d == 1) for(int i = 1; i <= n; ++i) cout<<vs[i]<<' ';;cout<<'\n';
	// if(d == 1) for(int i = 1; i <= n; ++i) cout<<st[i]<<' ';;cout<<'\n';
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v : to[u]) if(!vs[v] && !rm[v])
			if(--dg[v] <= 1) rm[v] = 1 , q.push(v);
	}
	// if(d == 1) for(int i = 1; i <= n; ++i) cout<<rm[i]<<' ';;cout<<'\n';
	for(int i = 1; i <= n; ++i) c[i] = 1e9;
	for(int i = 1; i <= n; ++i) if(!vs[i] && !rm[i] && dg[i] <= 1) c[i] = 1 , q.push(i);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(c[u] == d) continue;
		for(int v : to[u]) if(!vs[v] && !rm[v] && c[v] > n)
			if(--dg[v] <= 1) c[v] = c[u] + 1 , q.push(v);
	}
	int ck = 0;
	for(int i = 1; i <= n; ++i) if(!vs[i] && !rm[i] && c[i] > n) ++ck;
	if(!ck) ck = 1;
	return ck <= w;
}
bool chk(){
	dfs2(r1);
	for(int i = 1; i <= n; ++i){
		if(anc[i] == r1 && f[i] <= k && solve(i , k - f[i])) return 1;
	}
	return 0;
}

void gdm(){ // get diameter
	int w = 0;
	vs.reset() , q.push(1);
	while(!q.empty()){
		int u = q.front();
		q.pop() , vs[u] = 1 , w = u;
		for(int v : to[u]) if(!vs[v]) q.push(v);
	}
	vs.reset() , q.push(w) , fr[w] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop() , vs[u] = 1 , w = u;
		for(int v : to[u]) if(!vs[v]) fr[v] = u , q.push(v);
	}
	vector<int> vec;
	while(w) vec.E(w) , w = fr[w];
	dz = (int)vec.size() , r1 = vec[dz / 2 - 1] , r2 = vec[dz / 2];
}
void dfs1(int u , int f , int a){
	anc[u] = a , fa[u] = f;
	for(int v : to[u]) if(v != f) s[u].E(v) , dfs1(v , u , a);
}

signed main(){
	freopen("hub.in" , "r" , stdin) , freopen("hub.out" , "w" , stdout);
	// freopen("data.in" , "r" , stdin) , freopen("data.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

	cin>>_c>>T;
	while(T--){
		cin>>n>>k;
		for(int i = 1 , u , v; i < n; ++i) cin>>u>>v , to[u].E(v) , to[v].E(u);
		if(k == n){ cout<<"0\n"; continue; }
		gdm() , dfs1(r1 , r2 , r1) , dfs1(r2 , r1 , r2);
		int L = 1 , R = dz / 2;
		while(L < R) d = (L + R) >> 1 , chk() ? R = d : L = d + 1;
		cout<<L<<'\n';
		for(int i = 1; i <= n; ++i) to[i].clear() , s[i].clear();
	}

	return 0;
}