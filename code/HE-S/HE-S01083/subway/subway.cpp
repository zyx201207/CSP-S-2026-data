#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
constexpr int N = 503, M = 5e5+3;
constexpr ll INF = 1e18;
vector<int> clr[M], Ti[M];
int w[M];
int c, n, m, d, q;
ll dis[N][N];
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			dis[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; ++i) scanf ("%d", &w[i]);
	for (int i = 1; i <= n; ++i) {
		int tk;
		scanf ("%d", &tk);
		while (tk--) {
			int ct, tt;
			scanf ("%d%d", &ct, &tt);
			clr[ct].push_back(i), Ti[ct].push_back(tt);
		}
	}
	for (int i = 1; i <= m; ++i) {
//		cout << i << endl;
		for (int j = 0; j < clr[i].size(); ++j) {
			for (int k = 0; k < clr[i].size(); ++k) {
//				cout << j << " " << k << endl;
				int ct1 = clr[i][j], ct2 = clr[i][k];
				dis[ct1][ct2] = min (dis[ct1][ct2], (long long)((long long)Ti[i][j] + (long long)Ti[i][k]));
			}
		}
	}
	
	//Floyd
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j){
				dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	} 
//	for (int i = 1; i <= n; ++i)  {
//		for (int j = 1; j <= n; ++j) cout << dis[i][j] << " ";
//		cout << endl;
//	}
//		
	for (int kek = 1; kek <= q; ++kek) {
		int x, y;
		ll tans = INF;
		scanf ("%d%d", &x, &y);
		for (int i = 0; i < clr[x].size(); ++i) {
			for (int j = 0; j < clr[y].size(); ++j) {
				int cx = clr[x][i], cy = clr[y][j];
				tans = min (tans, (long long)w[x] + (long long)w[y] + dis[cx][cy] + Ti[x][i] + Ti[y][j]);
			}
		}
		printf ("%lld\n", tans);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
/*
17:45 我好像干掉了这家伙！
我在MX模拟赛的时候从来没有切过T2
祝我成功！
*/ 
