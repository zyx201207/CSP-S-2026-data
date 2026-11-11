//1s 1G
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define pii pair<int, int>
#define fs first
#define se second
#define lp p * 2
#define rp p * 2 + 1
#define pb push_back
#define all(s) s.begin(), s.end()
#define db double
#define i128 __int128
#define Mid auto mid = (l + r) / 2
using namespace std;
template<class T1, class T2>
void cmax(T1 &a, T2 b){if(a < b)a = b;}
template<class T1, class T2>
void cmin(T1 &a, T2 b){if(a > b)a = b;}
const int N = 505, M = 5e5 + 5;
int testcase, n, m, d, q;
vector<pii>station[M];
int dis[N][N];
int w[M], k[N];
void solve(){
	cin >> testcase >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++){
			int a, t;
			cin >> a >> t;
			station[a].pb({i, t});
		}
	}
	
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i ++){
		dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i ++){
		for(int j = 0; j < (int)station[i].size(); j ++){
			for(int e = 0; e < (int)station[i].size(); e ++){
				pii a = station[i][j], b = station[i][e];
				cmin(dis[a.fs][b.fs], a.se + b.se);
			}
		}
//		cerr << station[69].size() << "\n";
	}
	
//	for(auto a : station[69]){
//		cerr << a.fs << " " << a.se << "\n";
//	}
	for(int e = 1; e <= n; e ++){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				cmin(dis[i][j], dis[i][e] + dis[e][j]);
			}
		}
	}
//	return ; 
	while(q --){
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
//		cerr << x << " " << y << "\n";
		for(auto a : station[x]){
//			cerr << a.fs << " " << a.se << "\n";
			for(auto b : station[y]){
//				cerr << a.fs << " " << b.fs << "\n";
				cmin(ans, dis[a.fs][b.fs] + a.se + b.se);
			}
		}
//		cerr << ans << "\n";
		cout << ans + w[x] + w[y] << "\n";
//		cerr << "\n\n";
	}
//	cerr << (sizeof(station) * sizeof(pii) + sizeof(dis) * sizeof(int)) / 1048576.0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while(T --){
		solve();
	}
}
/*
luogu : bugaboost114514
Oct31==Dec25?
题面更正-ed 
qswl怎么老RE 
16:06
*/

