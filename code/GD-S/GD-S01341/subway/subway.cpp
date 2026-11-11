#include<bits/stdc++.h> 
#define int long long

using namespace std;

const int N = 5e5 + 10, M = 500 + 10, INF = 2e18;

int _, n, m, D, Q, W[N], K[N];
int tag[N], dist[M][M];
vector<int> A[M], T[M];
unordered_map<int, int> st[N];
struct QUERY{
	int x, y;
}Qs[N];

void floyd(){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void solve(){
	cin >> _ >> n >> m >> D >> Q;
	for(int i = 1; i <= m; i++) cin >> W[i];
	for(int i = 1; i <= n; i++){
		cin >> K[i];
		A[i].push_back(0), T[i].push_back(0);
		for(int j = 1, a, t; j <= K[i]; j++){
			cin >> a >> t, A[i].push_back(a), T[i].push_back(t);
			st[A[i][j]][i] = j, tag[A[i][j]] += (1 << i);
		}
	}
	for(int i = 1; i <= Q; i++) cin >> Qs[i].x >> Qs[i].y;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) dist[i][j] = INF;
		dist[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		vector<int> tmp;
		for(int j = 1; j <= n; j++) if(st[i][j]) tmp.push_back(j);
		int tot = (int)tmp.size();
		for(int x : tmp) for(int y : tmp)
			dist[x][y] = min(dist[x][y], T[x][st[i][x]] + T[y][st[i][y]]);
	}
	floyd();
	for(int i = 1; i <= Q; i++){
		int x = Qs[i].x, y = Qs[i].y;
		vector<int> lx, ly;
		for(int j = 1; j <= n; j++){
			if(st[x][j]) lx.push_back(j);
			if(st[y][j]) ly.push_back(j);
		}
		int res = INF;
		for(int xx : lx) for(int yy : ly)
			res = min(res, T[xx][st[x][xx]] + dist[xx][yy] + T[yy][st[y][yy]]);
		cout << res + W[x] + W[y] << "\n";
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++) cout << dist[i][j] << " ";
//		cout << "\n";
//	}
//	cout << timer << "\n";
//	cout << "aaaaa\n";
}

signed main(){
//	freopen("subway7.in", "r", stdin);
//	freopen("tmp.ans", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--) solve();
	return 0;
}
