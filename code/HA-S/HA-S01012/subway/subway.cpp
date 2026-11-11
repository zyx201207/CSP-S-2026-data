#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505, MAXM = 5e3+10;
int c, n, m, d, q;
int t1[MAXM], staCnt[MAXN], valueSum, x, y;
int passedStations[MAXN][MAXM], value[MAXM][MAXM];
bool haveArrived[MAXM] = {};
void printValue() {
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= m; j++) cout << value[i][j] << ' ';
		cout << '\n';
	}
}
void dfs(int earliestBegin, int begin, int target) {
//	cout << "check1\n" << "now haveArrived is" << haveArrived << '\n';
//	cout << "Now from " << begin << " to " << target <<", and the sum is " << valueSum << '\n';
	if(begin == target) {
//		cout << "check2\n" << "now sum is" << valueSum << '\n';
		value[earliestBegin][target] = min((value[earliestBegin][target] == 0 ? INT_MAX : value[earliestBegin][target]), valueSum);
		value[target][earliestBegin] = value[earliestBegin][target];
		return;
	} else if(haveArrived[begin]) {
//		cout << "check3\n";
		return;
	}
//	cout << "check4\n";
	haveArrived[begin] = true;
	for(int i = 1; i <= m; i++) {
		if(begin == i || value[begin][i] == 0) continue;
		valueSum += value[begin][i];
//		cout << "Now from " << begin << " to " << i <<", and the sum is " << valueSum << '\n';
		dfs(earliestBegin, i, target);
		valueSum -= value[begin][i];
	}
	haveArrived[begin] = false;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> t1[i];
	for (int i = 1; i <= n; i++) {
		cin >> staCnt[i];
		int t2[MAXM] = {};
		for(int j = 1; j <= staCnt[i]; j++) cin >> passedStations[i][j] >> t2[passedStations[i][j]];
		for(int j = 1; j <= staCnt[i]; j++) {
			for (int k = 1; k <= staCnt[i]; k++) {
				value[passedStations[i][j]][passedStations[i][k]] = min((value[passedStations[i][j]][passedStations[i][k]] == 0 ? INT_MAX : value[j][k]), t2[passedStations[i][j]] + t2[passedStations[i][k]]);
				if(j == k) {
					value[passedStations[i][j]][passedStations[i][k]] = t2[passedStations[i][j]];
				}
			}
		}
	}
//	printValue();
	for(int i = 0; i < q; i++) {
		cin >> x >> y;
		valueSum = 0;
		dfs(x, x, y);
//		printValue();
		cout << t1[x] + t1[y] + value[x][y] << '\n';
//		cout << value[x][y] << '\n';
	}
	return 0;
}