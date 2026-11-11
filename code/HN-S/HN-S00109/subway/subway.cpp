#include <bits/stdc++.h>
using namespace std;

#define cout fout
#define cin fin
#define ll long long 

ifstream fin("subway.in");
ofstream fout("subway.out");

const int N = 505;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
ll dis[N][N];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dis[i][j] = INF;
		dis[i][i] = 0;
	}
	vector <int> w(m + 1);
	vector <vector<array<ll, 2> > > vp(m + 1); 
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			vp[a].push_back({i, t});
		}
	}
	
	for (int i = 1; i <= m; i++) {
		for (auto pa : vp[i]) for (auto pb : vp[i]) {
			ll d = pa[1] + pb[1];
			dis[pb[0]][pa[0]] = dis[pa[0]][pb[0]] = min(d, dis[pa[0]][pb[0]]);
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << dis[i][j] << '\t';
//		}
//		cout << '\n';
//	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = INF;
		
		for (auto pa : vp[x]) for (auto pb : vp[y]) {
			ans = min(pa[1] + pb[1] + dis[pa[0]][pb[0]], ans);
		}
		
		cout << ans + w[x] + w[y] << '\n';
	}
	
} 



/*


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2







//测试点编号c 25、地铁线路数n 500、
//地铁站数m 5e5、每个地铁站最多被d 20 条线路经过，以及出行计划数q 1e5
//输入的第二行包含m个正整数w1,w2,...,wm，依次表示从每个地铁站的地铁口走到站厅需要的时间。
//输入的第i+2(1≤i≤n) 行包含1+2ki 个正整数，其中第一个正整数为ki，表示第i条线路经过的地铁站数；
//接下来2ki个正整数为ai,1,ti,1
// ai,j 表示第 i 条线路经过的第j 个地铁站，ti,j 表示从该地铁站的站厅走到第i条线
//路的站台需要的时间。
//输入的第r+n+2(1≤r≤q) 行包含两个正整数xr,yr，分别表示第r 个出行计
//划的起点和终点所在的地铁站编号。

*/
