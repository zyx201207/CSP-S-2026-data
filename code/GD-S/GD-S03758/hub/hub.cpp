#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
template<class T>bool ckmax(T &x,const T y){return x<y?x=y,1:0;}
template<class T>bool ckmin(T &x,const T y){return x>y?x=y,1:0;}
inline int read(){
	int f=1,w=0,ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) w=(w<<3)+(w<<1)+(ch^48);
	return f*w;
}
#define go(i,u) for(int i=h[(u)];i;i=ne[i])
const int N = 1e6 + 10;
int c, t, n, k;
int h[N], e[N * 2], ne[N * 2], idx;
void add(int a, int b) {
	idx++;
	e[idx] = b, ne[idx] = h[a], h[a] = idx;
}
int f[N], cnt[N], dep[N], g[N];
void dfs(int u, int fa, int ban, int x) {
	dep[u] = dep[fa] + 1, f[u] = fa, cnt[u] = 0, g[u] = dep[u];
	go(i, u) {
		int v = e[i];
		if (v == fa) continue;
		if (v == ban) {
			f[v] = u;
			continue;
		}
		dfs(v, u, ban, x);
		cnt[u] += cnt[v], ckmax(g[u], g[v]);
	}
	if (g[u] - dep[u] >= x) cnt[u]++;
}
bool check(int x) {
	rep(i, 1, n) {
		rep(j, 1, n) {
			if (j == i) continue;
			dfs(i, 0, j, x);
			dfs(j, f[j], i, x);
			if (cnt[i] + cnt[j] <= k) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(), t = read();
	while (t--) {
		n = read(), k = read();
		idx = 0;
		rep(i, 1, n) h[i] = 0;
		rep(i, 1, n - 1) {
			int u = read(), v = read();
			add(u, v), add(v, u);
		}
		int l = 0, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

