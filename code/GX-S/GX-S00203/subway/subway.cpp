#include <iostream>
#include <algorithm>

using namespace std;

int c, n, m, d, q;
const int MAXM = 500000;
const int MAXQ = 100000;
const int MAXN = 500;
const int MAXD = 20;
long long wts[MAXM];
int wayn[MAXM];
long long ts[MAXM][MAXD];
int ways[MAXM][MAXD];
int plans[2 * MAXQ];
long long times[MAXN][MAXN];
const long long inf = 2LL << 60;

void build() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			times[i][j] = inf;
		}
		times[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < wayn[i]; j++) {
			for (int k = j + 1; k < wayn[i]; k++) {
				int w1 = ways[i][j];
				int w2 = ways[i][k];
				long long t = ts[i][j] + ts[i][k];
				if (times[w1][w2] > t) {
					times[w1][w2] = times[w2][w1] = t;
				}
				
			}
		}
	}
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (times[i][k] + times[k][j] < times[i][j]) {
					times[i][j] = times[i][k] + times[k][j];
				}
			}
		}
	}
}

long long process(int from, int to) {
	long long base = wts[from] + wts[to];
	long long res = inf;
	for(int i = 0; i < wayn[from]; i++) {
		for(int j = 0; j < wayn[to]; j++) {
			int w1 = ways[from][i];
			int w2 = ways[to][j];
			long long t = times[w1][w2] + base + ts[from][i] + ts[to][j];
			res = min(res, t);
		}
	}
	return res;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0; i < m; i++) {
		cin >> wts[i];
	}
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for(int j = 0; j < k; j++) {
			int a;
			long long t;
			cin >> a >> t;
			a -= 1;
			ts[a][wayn[a]] = t;
			ways[a][wayn[a]] = i;
			wayn[a] += 1;
		}
	}
	build();
	for(int i = 0; i < q; i++) {
		int from, to;
		cin >> from >> to;
		plans[2*i] = from - 1;
		plans[2*i + 1] = to - 1;
	}
	for(int i = 0; i < q; i++) {
		cout << process(plans[2*i], plans[2*i + 1]) << endl;
	}
	return 0;
}
