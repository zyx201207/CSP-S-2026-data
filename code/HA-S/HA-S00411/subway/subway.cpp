#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 500005, Q = 100005;
int c, n, m, d, q;
int w[M];
int k[N];
struct node{
	int a, t;
}inp[N][N];
struct ask{
	int x, y;
}que[Q];
int dis[N][N];
//void dijkstra(int S){
//	
//}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis, 0x3f, sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++){
			cin >> inp[i][j].a >> inp[i][j].t;
		}
	}
	for (int i = 1; i <= q; i++){
		cin >> que[i].x >> que[i].y;
		cout << w[que[i].x] + w[que[i].y] << "\n";
	}
}
