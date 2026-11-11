#include <bits/stdc++.h>
#define enl putchar('\n')
#define ys puts("YES")
#define md int mid=l+r>>1
#define len(l, r) ((r)-(l)+1)
#define fst first
#define snd second
using ll=long long;
using ull=unsigned long long;
using pii=std::pair<int, int>;
using namespace std;
const int MAX=1e6+10, MAXM=1e3+10, MOD=1e9+7;
const ll INF=1e9;
int cid, tc=1;
int n, K;
vector<int> G[MAX];
int anc[MAX];
ll dis[MAX], ans;
bool vis[MAX];
int find(int x) {
	if (anc[x]==x) return x;
	return anc[x]=find(anc[x]);
}
void merge(int x, int y) {
	x=find(x);y=find(y);
	if (x==y) return;
	anc[x]=y;
}
void npw() {
	for (int t=0;t<1<<n;t++) if (__builtin_popcount(t)==K) {
		for (int i=1;i<=n;i++) anc[i]=i;
		for (int u=1;u<=n;u++) if ((t>>(u-1))&1) for (auto v:G[u]) if ((t>>(v-1))&1) merge(u, v);
		int cnt=0;
		fill(vis+1, vis+n+1, false);
		for (int u=1;u<=n;u++) if ((t>>(u-1))&1) if (!vis[find(u)]) {
			vis[find(u)]=true;
			cnt++;
		}
		if (cnt>2) continue;
		fill(dis+1, dis+n+1, INF);
		fill(vis+1, vis+n+1, false);
		queue<int> q;
		for (int i=0;i<n;i++) if ((t>>i)&1) {
			q.push(i+1);
			dis[i+1]=0;
		}
		while (q.size()) {
			int u=q.front();
			q.pop();
			if (vis[u]) continue;
			vis[u]=true;
			for (auto v:G[u]) if (dis[u]+1<dis[v]) {
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
		ans=min(ans, *max_element(dis+1, dis+n+1));
	}
}
void INIT() {
	ans=INF;
}
void EXE() {
	int u, v;
	for (int i=1;i<n;i++) {
		scanf("%d %d", &u, &v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	if (cid<=3) npw();
	printf("%lld\n", ans);
}
void CLEAR() {
	for (int i=1;i<=n;i++) G[i].clear();
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d %d", &cid, &tc);
	while (tc--) {
		scanf("%d %d", &n, &K);
		INIT();
		EXE();
		CLEAR();
	}
	return 0;
}