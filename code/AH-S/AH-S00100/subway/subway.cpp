#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int c, n, m, d, q, k, a, t, x, y;
long long w[500050];
vector<int> A[500005], T[500005];
long long Dis[505][505];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			A[a].push_back(i);
			T[a].push_back(t);
		}
	}
	memset(Dis, 0x3f, sizeof Dis);
	for (int i = 1; i <= n; i++) Dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int s = A[i].size();
		for (int j = 0; j < s; j++) {
			for (int k = j + 1; k < s; k++) {
				Dis[A[i][j]][A[i][k]] = min(Dis[A[i][j]][A[i][k]], T[i][j] + T[i][k] * 1LL);
				Dis[A[i][k]][A[i][j]] = Dis[A[i][j]][A[i][k]];
			}
		}
	}
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);
	while (q--) {
		cin >> x >> y;
		int s1 = A[x].size(), s2 = A[y].size();
		long long Res = 0x3f3f3f3f3f3f3f3f;
		for (int j = 0; j < s1; j++) {
			for (int k = 0; k < s2; k++) {
				Res = min(Res, Dis[A[x][j]][A[y][k]] + T[x][j] + T[y][k]);
			}
		}
		cout << Res + w[x] + w[y] << '\n';
	}
	return 0;
}
//Oct31==Dec25?
// OK 100pts 15:00

