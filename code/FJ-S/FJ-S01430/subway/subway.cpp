#include <iostream>
#include <cstring>
#include <queue>
#define pii pair <int, int>
#define int long long
using namespace std;
const int N=500505, M=2e6+5;

int c, n, m, d, q;
int a[N];
int fir[N], nxt[M], to[M], w[M];
int dis[N];

inline void add (int u, int v, int W) {
	static int num=0;
	to[++num]=v;
	nxt[num]=fir[u];
	fir[u]=num;
	w[num]=W;
}

inline void dij (int s, int t) {
	priority_queue <pii, vector <pii>, greater <pii>> q;
	memset (dis, 63, sizeof dis);
	dis[s]=0;
	q.push ({0, s});
	while (!q.empty ()) {
		int u=q.top ().second, d=q.top ().first;
		q.pop ();
		for (int i=fir[u]; i; i=nxt[i]) {
			int v=to[i];
			if (dis[v]>dis[u]+w[i]) {
				dis[v]=dis[u]+w[i];
				q.push ({dis[v], v});
			}
		}
	}
	cout<<(dis[t]+a[s]+a[t])<<'\n';
}

signed main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio (0), cin.tie (0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1; i<=m; i++) cin>>a[i];
	for (int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for (int j=1, v, W; j<=k; j++) {
			cin>>v>>W;
			add (m+i, v, W);
			add (v, m+i, W);
		}
	}
	while (q--) {
		int s, t;
		cin>>s>>t;
		dij (s, t);
	}
	return 0;
}



//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 17 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
