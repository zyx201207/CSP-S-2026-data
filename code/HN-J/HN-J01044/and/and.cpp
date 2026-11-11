#include <iostream>
#undef _
using namespace std;

// DISGUSTING

// and.cpp

// 45pts plz

const int N = 2e6 + 3;

int n, m;
int A[N];

int dfs(int x, int s, int c) {
	if (c >= m) return s;
	if (x > n || s == 0) return 0;
	return max(dfs(x + 1, s & A[x], c + 1), dfs(x + 1, s, c));
}

int main() {
	ios::sync_with_stdio(false);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> A[i];
	}
	
	if (n <= 20) cout << dfs(0, 2147483647, 0) << endl;
	else if (m == 1) {
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			res = max(res, A[i]);
		}
		cout << res << endl;
	} else if (m == 2) {
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				res = max(res, A[i] & A[j]);
			}
		}
		cout << res << endl;
	} else {
		cout << 0 << endl;
	}
	
	return 0;
} 
