#include <bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long;
const int maxm = 5e5 + 5;
const int maxn = 605;
const int inf = 1e9;

//内存有1024Mb，可以开maxn * maxm 
int c, n, m, d, q;
//测试点编号？？  地铁线路数  地铁站数  每个地铁站最多包含线路数  出行计划数 
int w[maxm], k[maxn];
vector<int> a[maxn], t[maxn];
int sta, ed;
ll ans;
int stat[maxm][30], stt[maxm];//记录每个站点由那些线路经过    有几条线
int satt[maxm][30];//记录该线路的次换乘站是原本线路的第几站 
int to[maxn * 2], nxt[maxn * 2], val[maxn * 2], h[maxn], cnt;
int dp[maxn];//dfs的路径答案 
bool vis[maxn];//复用性 
vector<int> l1, l2;
void add(int a, int b, int c) {
	to[++cnt] = b;
	val[cnt] = c;
	nxt[cnt] = h[a];
	h[a] = cnt;
}
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	for (int i = h[u]; i; i = nxt[i]) {
		int v = to[i];//下一点 
		if (dp[v] > dp[u] + val[i]) {
//			cout << i << " : ";
//			cout << dp[v] << " = " << dp[u] << " + " << val[i] << "\n";
			dp[v] = dp[u] + val[i];
		}
		dfs(v);
	}
}
void solve() {
	bool flagt = 0;
	ll anst = 0;
	for (int i = 1; i <= n; ++i) {//同线路特判 
		bool flag1 = 0, flag2 = 0;
		anst = 0;
		for (int j = 1; j <= k[i]; ++j) {
//			cout << a[i][j] << " ";
			if (a[i][j] == sta) {
				flag1 = 1;
				anst += t[i][j]; 
//				cout << i << " " << j << " " << t[i][j] << "\n";
				l1.push_back(i);
			} 
			if (a[i][j] == ed) {
				flag2 = 1;
				anst += t[i][j];
//				cout << i << " " << j << " " << t[i][j] << "\n";
				l2.push_back(i);
			} 
//			cout << "\n";
		}
		if (flag1 == 1 && flag2 == 1) {
			flagt = 1;
			//说明在同一条线路上
			if (!ans) ans = anst;
			else ans = min(ans, anst);
		}
	}
	if (flagt == 1) {
		ans += w[sta] + w[ed];
		cout << ans << "\n";
		return;
	}
//	cout << l1 << " " << l2 << "\n";
	//不同线路 
	ans += w[sta] + w[ed];
	
	for (int i = 1; i <= n; ++i) dp[i] = inf;
	for (int yt : l1) {
		dp[yt] = 0;
	}
//	for (int i = 1; i <= n; ++i) cout << dp[i] << " ";
//	cout << "\n";
	int ansr = inf;
	for (int yt1 : l1) { 
		dfs(yt1);
		int tpa = 0;
		for (int j = 1; j <= k[yt1]; ++j) {
			if (a[yt1][j] == sta) {
				tpa = t[yt1][j];
			}
		}
		for (int yt : l2) {
			int tpp = 0;
			for (int i = 1; i <= k[yt]; ++i) {
				if (a[yt][i] == ed) {
					tpp = t[yt][i];
				}
			}
			ansr = min(ansr, dp[yt] + tpp + tpa);
		}
	}
	

	ans += ansr;
	cout << ans << "\n";
//	for (int i = 1; i <= n; ++i) {
//		cout << dp[i] << " ";
//	}
	
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	AC;
	cin >> c >> n >> m >> d >> q;
	//测试点编号？？  地铁线路数  地铁站数  每个地铁站最多包含线路数  出行计划数 
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];//每个地铁站的进出站时间 
	}
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];//第i条地铁经过k[i]个站 
		a[i].push_back(0);
		t[i].push_back(0);
		for (int j = 1; j <= k[i]; ++j) {
			int a1, t1;
			cin >> a1 >> t1;
			a[i].push_back(a1);//第i条线路经过的站点 
			t[i].push_back(t1);//该线路的站台到站厅的时间 
			//第i条线路进入此线路的第j个站点的站厅所需时间 
			stat[a1][++stt[a1]] = i;
			satt[a1][stt[a1]] = j;
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (stt[i] > 1) {
			//说明为换乘站
			//d <= 20  
			for (int j = 1; j <= stt[i]; ++j) {//当前换乘站的第j条线 
				for (int l = j + 1; l <= stt[i]; ++l) {//当前换乘站的第l条线 
					add(stat[i][j], stat[i][l], t[stat[i][j]][satt[i][j]] + t[stat[i][l]][satt[i][l]]);
//					cout << stat[i][j] << " " << stat[i][l] << " " << t[stat[i][j]][satt[i][j]] << " " << t[stat[i][l]][satt[i][l]]<< "\n";
				}
			}	
		}
	}
	for (int i = 1; i <= q; ++i) {
		cin >> sta >> ed;//起点  终点 
		ans = 0;
		solve();
	}
	//类似于最短路，但是只记录步行时间，所以尽量少换乘
	//对于换乘，时间为 t[i][k] + t[j][k]，i,j 为线路, k为站点
	/*
	0 3 7 20 2
	8 3 6 1 7 2 9
	3 1 4 2 5 5 100
	3 2 6 3 1 7 2
	4 3 2 5 100 4 6 6 7
	1 6
	2 3
	*/
	//rp++ rp += inf  求过！！ 靠你了 subway! 
	
	
	
	return 0;
}
