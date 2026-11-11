#include<iostream>
#include<cstring>
#define N 1005
using namespace std;

long long c, n, m, d, q, k;
long long w[N], a[N], b[N];
long long mp[N][N], dis[N][N];

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	memset(mp, 0x3f, sizeof mp);
	memset(dis, 0x3f, sizeof dis);
	for(long long i = 1; i <= m; i++) cin >> w[i];
	for(long long i = 1; i <= n; i++) {
		cin >> k;
		for(long long j = 1; j <= k; j++) {
			cin >> a[j] >> b[j];
		}
		for(long long j = 1; j <= k; j++) {
			for(long long l = 1; l < j; l++) {
				long long jj = a[j], ll = a[l];
				mp[jj][ll] = mp[ll][jj] = min(mp[jj][ll], b[j] + b[l]);
				dis[jj][ll] = dis[ll][jj] = mp[ll][jj];
				dis[jj][jj] = dis[ll][ll] = 0;
//				cout << jj << " " << ll << ":" << mp[jj][long long] << endl;
			}
		}
	}
	
//	for(long long i = 1; i <= m; i++) {
//		for(long long j = 1; j <= m; j++) cout << mp[i][j] << " ";
//		cout << endl;
//	}

	
	
	for(long long l = 1; l <= m; l++) {
		for(long long i = 1; i <= m; i++) {
			for(long long j = 1; j <= m; j++) {
				if(i == l || j == l || i == j) continue;
//				cout << i << " " << j << " " << l << endl;
				dis[i][j] = min(dis[i][j], dis[i][l] + dis[l][j]);
			}
		}
	}
	
//	cout << dis[2][1] << " " << dis[3][2] << endl;
	
	while(q--) {
		long long u, v;
		cin >> u >> v;
		cout << dis[u][v] + w[u] + w[v] << endl;
	}

	cout.flush();
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

