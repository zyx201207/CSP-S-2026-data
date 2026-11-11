#include<bits/stdc++.h> 
#define fstio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 400;

struct Node{int line, di, cst;};

int c, n, m, d, q;
int w[N], a[N][M], k[N], dis[M][M], t[N][M];
// n地铁线路数、n地铁站数、m每个地铁站、d最多被几条线路经过，q以及出行计划数

vector<pair<int, int> > g[N]; // g[i] = {<j, w>} 表示线路i有一条直接能换到j的点，花费w
vector<Node> st[M];

int minnn(int u){
	int minn = 1e9;
	for (auto cur : st[u]) minn = min(minn, t[cur.line][cur.di]);
	return minn;
}

void floyd(){
	
	memset(dis, -1, sizeof dis);
	for (int i = 1; i <= n; i ++)
		for (auto j : g[i])
			dis[i][j.first] = dis[j.first][i] = j.second;
	
	for (int i = 1; i <= n; i ++) dis[i][i] = 0;
	
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (i != j && j != k && i != k)
					if (dis[i][j] > dis[i][k] + dis[k][j])
						dis[i][j] = dis[i][k] + dis[k][j];

//	for (int i = 1; i <= 3; i ++){
//		for (int j = 1; j <= 3; j ++){
//			cout << dis[i][j] << ' ';
//		}
//		cout << '\n';
//	}
}

int main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	fstio; cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1, tp; i <= n; i ++){
		cin >> k[i]; 
		for (int j = 1; j <= k[i]; j ++){
			cin >> a[i][j] >> t[i][j];
			st[a[i][j]].push_back({i, j, t[i][j]});
		}
	}
	for (int i = 1; i <= m; i ++){
		for (Node cur1 : st[i]){
			for (Node cur2 : st[i]){
				if (cur1.line == cur2.line) continue;
				g[cur1.line].push_back(make_pair(cur2.line, (t[cur2.line][cur2.di] + t[cur1.line][cur1.di])));
				g[cur2.line].push_back(make_pair(cur1.line, (t[cur1.line][cur1.di] + t[cur2.line][cur2.di])));
			}
		}
	}
	
//	cout << g[1][1].first << ' ' << g[1][1].second << '\n';
	
	floyd();
	
	while (q --){
		int l, r; cin >> l >> r;
		cout << w[l] + w[r] + dis[st[l][0].line][st[r][0].line] + minnn(l) + minnn(r) << '\n';
	}
	
	return 0;
}
