#include <iostream>
using namespace std;
int su[500005];
int a[505][1005]; // i = subway xian j = subway xian jingguo de zhan
bool b[1005][505]; // di i ge zhan shifou you j(xian) jingguo
int t[505][1005]; // i = subway xian j = subway zhantai to zhanting
int xz[505];
// yixia is tem,need clear
bool ded[505];    // yijing fangwen de ditei xianlu 
bool dex[5000005]; //yij fangwen d zhan
// const liang
int c, n, m, d, q;
int dfs(int xian, int zhan, int bu, int ry) { // xianlu, xian->zhan de index
	int index = a[xian][zhan];
	if (index == ry) {
		return bu + t[xian][zhan];
	}
	else {
		int jumin = -1;
		for (int i = 1; i <= m; i++) { // xian
			if (!(ded[i]) && b[zhan][i]) {
				ded[i] = true;
				for (int j1 = 1; j1 <= xz[i]; j1++) { // zhan
					int j = a[i][j1];
					if (!dex[j]){
						dex[j] = true;
						int lamin = dfs(i, j1, bu + t[xian][zhan] + t[i][zhan], ry);
						dex[j] = false;
						if (jumin == -1) {
							jumin = lamin;
						}
						if (lamin != -1 && jumin != -1) {
							jumin = min(jumin, lamin);
						}
					}
				}
				ded[i] = false;
			} 
		}
		if (jumin != -1) {
			return jumin;
		}
		else {
			return -1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	/*freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);*/
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++) {
		cin >> su[i];
	}
	for (int i = 1; i <= m; i++) {
		int ki;
		cin >> ki;
		xz[i] = ki;
		for (int j = 1; j <= ki; j++) {
			cin >> a[i][j] >> t[i][j];
			b[a[i][j]][i] = true;
		}
	}


	while (q--) {
		int xy, ry;
		cin >> xy >> ry;
		dex[xy] = true;
		int bu = su[xy] + su[ry];
		int jumin = -1;
		for (int i = 1; i <= m; i++) { // xian
			if (!(ded[i]) && b[xy][i]) {
				int xxyy = lower_bound(a[i] + 1, a[i] + 1 + n, xxyy) - a[i];
				ded[i] = true;
				for (int j1 = 1; j1 <= xz[i]; j1++) { // zhan
					int j = a[i][j1];
					if (!dex[j]) {
						dex[j] = true;
						int lamin = dfs(i, j, bu + t[i][xxyy], ry);
						dex[j] = false;
						if (jumin == -1) {
							jumin = lamin;
						}
						if (lamin != -1 && jumin != -1) {
							jumin = min(jumin, lamin);
						}
						
					}
				}
				ded[i] = false;
			}
		}
		cout << jumin << endl;
		for (int i = 1; i <= m; i++) {
			dex[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			ded[i] = 0;
		}
	}
}
