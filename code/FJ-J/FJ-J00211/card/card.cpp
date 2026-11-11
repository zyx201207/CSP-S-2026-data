#include <iostream>
#include <vector>
using namespace std;

constexpr int N = 5e5;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n + 1);
	vector<int> cnt(m + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		vector<int> pos(m + 1, -1);
		int ed = 0;
		for (int j = i; j <= n; ++j) {
			if (pos[a[j]] == -1) {
				pos[a[j]] = ++ed;
			} else {
				ed = pos[a[j]];
				for (int k = 1; k <= m; ++k) {
					if (k != a[j] && pos[k] > ed) {
						pos[k] = -1;
					}
				}
			}
		}
		for (int j = 1; j <= m; ++j) {
			if (1 <= pos[j] && pos[j] <= ed) {
				++cnt[j];
			}
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		cout << cnt[i] << " ";
	}
	cout << endl;
	return 0;
}

