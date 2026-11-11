#include <bits/stdc++.h>

using namespace std;
const int N = 1e6+5; 
int n, k, d[N], ft[N], mxd[N], mk[N], ls[N], rs[N], f[N], g[N]; 
vector <int> e[N], ts; 

void dfs (int p, int fa) {
	d[p] = d[fa]+1; ft[p] = fa; 
	for (int i : e[p]) {
		if (i == fa) continue; 
		dfs(i, p); 
	}
}

void dfs2 (int p, int fa) {
	mxd[p] = 0; ft[p] = fa; 
	for (int i : e[p]) {
		if (mk[i] || i == fa) continue; 
		dfs2(i, p); mxd[p] = max(mxd[p], mxd[i]+1); 
	}
}

int chk (int len) {
	int ans = 0; 
	for (int i = 1;i <= n;i++) {
		if (mxd[i] >= len && !mk[i]) {
			ans++; 
		}
	}
	int L = ts.size()-1; 
	for (int i = 1;i <= L;i++) {
		ls[i] = 1; rs[i] = n; f[i] = g[i] = 1e9; 
	}
//	for (int i = 1;i <= L;i++) cout <<ts[i] << " "; cout << "\n"; 
	for (int i = 1;i < ts.size();i++) {
		int t = len-mxd[ts[i]];
		if (t <= 0) {
			ls[i] = i+1; rs[i] = i-1; 
		} 
		else {
			int l = max(1, i-t), r = min(L, i+t); 
			ls[r] = max(ls[r], l+1); rs[l] = min(rs[l], r-1); 
		}
	}
	for (int i = 2;i <= L;i++) ls[i] = max(ls[i], ls[i-1]); 
	for (int i = L-1;i >= 1;i--) rs[i] = min(rs[i+1], rs[i]); 
	f[0] = 0; g[0] = 0; 
	ls[0] = 1; rs[L+1] = L; 
	for (int i = 1;i <= L;i++) {
		if (ls[i-1] <= 1) f[i] = 1; 
		else f[i] = f[i-1]+1; 
		g[i] = min(g[i-1], f[ls[i-1]-1])+1; 
	}
	int mn = 1e9; 
	for (int i = 1;i <= L;i++) {
		if (rs[i+1] >= L) mn = min(mn, g[i]);  
	}
	return mn+ans <= k; 
}

void solve () {
	cin >> n >> k; ts.clear(); 
	for (int i = 1;i <= n;i++) e[i].clear(), mk[i] = 0; 
	for (int i = 1;i < n;i++) {
		int x, y; cin >> x >> y; 
		e[x].push_back(y); e[y].push_back(x); 
	}
	dfs(1, 0); 
	int x = 0; 
	for (int i = 1;i <= n;i++) if (d[i] > d[x]) x = i; 
	dfs(x, 0); 
	int y = 0; 
	for (int i = 1;i <= n;i++) if (d[i] > d[y]) y = i; 
	ts.push_back(0); 
	while (y != x) {
		ts.push_back(y); y = ft[y]; 
	}
	ts.push_back(x); 
	for (int i : ts) mk[i] = 1; 
	for (int i : ts) {
		dfs2(i, 0); 
	}
	int l = 0, r = n-1; 
	while (l < r) {
		int mid = l+r>>1; 
		if (chk(mid)) r = mid;
		else l = mid+1; 
	}
	cout << l << "\n"; 
	
}

int main () {
	freopen("hub.in", "r", stdin); 
	freopen("hub.out", "w", stdout); 
//	auto ST = clock(); 
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0); 
	int cid, T; 
	cin >> cid >> T; 
	while (T--) solve();
//	auto ED = clock(); 
//	cerr << (ED-ST)*1.0/CLOCKS_PER_SEC;  
	return 0; 
}
/*

I wonder 
why things have happened
could you imagine
the world is boring
......
the world is fading I know the fate
the world is fading I know the fate

I, I know all of you
have you, you followed me
me in your mind, mind was a dream 
a dream of the past
so I, I forget you
then you, forget me 
cause I, I'm destr0yer

SAKUZYO BEAM

I kill us all
it's the only way
it's over 

I'll kill 
I'll destroy the world
No matter what you do I won't stop
I'm the only one who's right

I'll kill 
I'll destroy the world
No matter what you do I won't stop
It is what it is 
It is not, it's not my fault 

SAKUZYO BEAM
*/
