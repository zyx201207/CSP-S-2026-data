#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

typedef long long lld;
typedef pair<int, int> pii;
const int maxn = 5e5 + 5;
int c, n, m, d, q;
struct station{
	int w, tc[505];
	vector<int> inl;
} s[maxn];
vector<pii> g[maxn];
vector<int> p[maxn], ans;
bool vis[maxn];

void dfs(int u, int y, int c, int l){
	if(u == y){
		ans.push_back(c + s[y].tc[l]);
		return;
	}
	for(pii p2: g[u]){
		int v = p2.first, vl = p2.second;
		if(vis[v]) continue;
		vis[v] = 1;
		if(l == vl) dfs(v, y, c, l);
		else dfs(v, y, c+s[u].tc[l]+s[u].tc[vl], vl);
		vis[v] = 0;
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cout.tie(0); cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> s[i].w;
	for(int i = 1; i <= n; i++){
		int k; cin >> k;
		for(int j = 1; j <= k; j++){
			int a, t; cin >> a >> t;
			s[a].tc[i] = t;
			s[a].inl.push_back(i);
			p[i].push_back(a);
			if(j > 1){
				g[a].push_back(make_pair(p[i][j-2], i));
				g[p[i][j-2]].push_back(make_pair(a, i));
			}
		}
	}
	while(q--){
		int x, y; cin >> x >> y;
		ans.clear();
		for(int cl: s[x].inl){
			memset(vis, 0, sizeof(vis));
			dfs(x, y, s[x].tc[cl], cl);
		}
		int mi = 0x3f3f3f3f;
		for(int an: ans){
			mi = min(mi, an);
		}
		cout << mi + s[x].w + s[y].w << endl;
	}
	return 0;
}
