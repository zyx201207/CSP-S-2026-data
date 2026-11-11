#include<bits/stdc++.h>
using namespace std;
const int MAXN = 507;
const int MAXM = 1e6 + 7;
const int MAXQ = 1e5 + 7;
int d[MAXM], k[MAXM], x[MAXM], y[MAXM];
int c, n, m, dx, q;
int w[MAXM], cnt, h[MAXM], nx[MAXM], to[MAXN];
bool o[MAXM];
void add(int u, int v, int wx){
	nx[cnt] = h[u];
	w[cnt] = wx;
	to[cnt] = v;
	h[u] = cnt++;
}
struct Node{
	int fa, wu, wx;
};
int minn = 0x3f3f3f3f3f;
void solve(int u, int fail, int fa, int wx){
	if(u == fail){
		minn = min(minn, wx + d[u]);
		return ;
	}
	for(int i = h[u]; ~i; i = nx[i]){
		int v = to[i], wxf = w[i];
		if(o[v] == true)continue;
		o[u] = true;
		solve(v, fail, u, wx + wxf);
		o[u] = false;
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(h, -1, sizeof(h));
	cin >> c >> n >> m >> dx >> q;
	for(int i = 1; i <= m; i++)cin >> d[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int tox, wx;
			cin >> tox >> wx;
			add(m + i, tox, wx);
			add(tox, m + i, wx);
		}
	}
	for(int i = 1; i <= q; i++){
		int xx, yy;
		cin >> xx >> yy;
		solve(xx, yy, -1, d[xx]);
		cout << minn << endl;
		minn = 0x3f3f3f3f3f;
	}
	return 0;
}
