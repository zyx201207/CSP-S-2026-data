#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10 , M = 55;
int w[N] , k[N];
#define pii pair <int , int>
struct graph {
	pii to;
	int v;
};
map <pii , vector <graph>[N + M] > v;
int dis[M][M][M][M] , mark[M][M];
int main() {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	int c , n , m , d , q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; i ++) cin >> w[i];
	memset(dis , 0x3f , sizeof dis);
	for (int i = 1 ; i <= n ; i ++) {
		dis[i][0][i][0] = 0;
		cin >> k[i];
		for (int j = 1 ; j <= k[i] ; j ++) {
			int x , y; cin >> x >> y;
			mark[x][i] = 1;
			dis[0][i][x][i] = dis[x][i][0][i] = dis[x][i][x][i] = dis[x][0][x][0] = dis[0][i][0][i] = 0;
			dis[x][i][x][0] = dis[x][0][x][i] = y;
		}
	}
	for (int kxx = m ; kxx >= 0 ; kxx --) {
		for (int kyy = n ; kyy >= 0 ; kyy --) {
			if (!mark[kxx][kyy]) continue;
			//cout << "---"; 
			for (int i = 1 ; i <= m ; i ++) {
				for (int j = 1 ; j <= m ; j ++) dis[i][0][j][0] = min(dis[i][0][j][0] , dis[i][0][kxx][kyy] + dis[kxx][kyy][j][0]);
			} 
		}
	}
	while (q --) {
		int x , y; cin >> x >> y;
		cout << dis[x][0][y][0] + w[x] + w[y] << "\n";
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
