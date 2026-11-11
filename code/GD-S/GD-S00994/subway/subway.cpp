#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N = 505,M = 5e5 + 5;

bool bst;
int c,n,m,d,q;
int w[M];
int len[N];
vector<pii> vec[N];
vector<pii> bel[M];
int f[N][N];
bool bed;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> m >> n >> d >> q;
	for (int i = 1;i <= n;i++) cin >> w[i];
	for (int i = 1;i <= m;i++){
		cin >> len[i];
		vec[i].push_back({0,0});
		for (int j = 1,x,y;j <= len[i];j++)
			cin >> x >> y,vec[i].push_back({x,y}),bel[x].push_back({i,y});
	}memset(f,0x3f,sizeof(f));
	for (int i = 1;i <= m;i++) f[i][i] = 0;
	for (int _ = 1;_ <= n;_++){
		for (pii i : bel[_]){
			for (pii j : bel[_]){
				int u = i.fi,v = j.fi,w = i.se + j.se;
				f[u][v] = f[v][u] = min(f[u][v],w);
			}
		}
	}
//	cerr << "f: -------------------------\n";
//	for (int i = 1;i <= m;i++)
//		for (int j = 1;j <= m;j++)
//			cerr << i << " " << j << " " << f[i][j] << "\n";
	for (int k = 1;k <= m;k++){
		for (int i = 1;i <= m;i++){
			for (int j = 1;j <= m;j++){
				if (i == j || j == k) continue;
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	while (q--){
		int x,y;
		cin >> x >> y;
		int ans = 0x3f3f3f3f3f3f3f3f;
		for (pii i : bel[x]){
			for (pii j : bel[y]){
				if (i.fi != j.fi) ans = min(ans,w[x] + w[y] + i.se + j.se + f[i.fi][j.fi]);
				else ans = min(ans,w[x] + w[y] + i.se + j.se); 
			}
		}cout << ans << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
