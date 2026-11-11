#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 5e6+50;
int e[N], ne[N], h[N], idx;
int f[N];
int u[N], v[N];
int ans = 0x3f3f3f3f;
int res = -0x3f3f3f3f;

void add(int a, int b) {
	e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

bool check(int x, int k) {
	int cnt = 0;
	while(x) {
		if(x & 1) ++cnt;
		if(cnt > k) return false;
		x >>= 1;
	}
	if(cnt < k) return false;
	return true;
}

int find(int x) {
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
} 

void dfs(int u, int fa, int dep) {
	res = max(res, dep);
	for(int i=h[u]; i!=-1; i=ne[i]) {
		int nw = e[i];
		if(nw == fa) continue;
		dfs(nw, u, dep+1);
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	for(int i=1; i<n; i++) {
		cin >> u[i] >> v[i];
	}
	int rt = n;
	for(int U=0; U<(1<<n); U++) {
		if(check(U, k)) {
			for(int i=1; i<=n; i++) {
				f[i] = i;
			}
			for(int i=0; i<n; i++) {
				if(U >> i & 1) {
					for(int j=h[i+1]; j!=-1; j=ne[j]) {
						int nw = e[j];
						if(U >> (nw-1) & 1) continue;
						int fi = find(i+1);
						int fv = find(nw);
						if(fi != fv) {
							f[fi] = fv;
						}
					}
				}
			}
			int k = -1;
			bool flag = 1;
			for(int i=0; i<n; i++) {
				if(U >> i & 1) {
					if(k != -1 && find(i+1) != k) {
						flag = 0;
						break;
					} else {
						k = find(i+1);
					}
				}
			}
			if(flag) {
				memset(h, -1, sizeof(h));
				idx = 0;
				++rt;
				for(int i=1; i<n; i++) {
					if((U >> (u[i]-1) & 1) && (U >> (v[i]-1) & 1)) continue;
					if((U >> (u[i]-1) & 1)) {
						add(rt, v[i]);
						add(v[i], rt);
					} else if((U >> (v[i]-1) & 1)) {
						add(rt, u[i]);
						add(u[i], rt);
					} else {
						add(u[i], v[i]);
						add(v[i], u[i]);
					}
				}
				res = -0x3f3f3f3f;
				dfs(rt, -1, 0);
				ans = min(ans, res);
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c, T = 1;
	cin >> c >> T;
	while(T--) {
		solve();
	}
	
	return 0;
}


/*
0 1
5 2
1 2
2 3
3 4
4 5


*/ 
