#include <iostream>
using namespace std;

const int N = 2e5;

bool cho[N + 5];
int a[N + 5];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cho[i] = true;
	}
	
	int res = 0;
	for (int j = 30; j >= 0; j--) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!cho[i]) {
				continue;
			}
			if ((a[i] >> j) & 1) {
				cnt++;
			}
		}
		if (cnt >= m) {
			res += (1 << j);
			for (int i = 1; i <= n; i++) {
				if (!((a[i] >> j) & 1)) {
					cho[i] = false;
				}
			}
		}
	} 
	cout << res << "\n";
	
	return 0;
}
