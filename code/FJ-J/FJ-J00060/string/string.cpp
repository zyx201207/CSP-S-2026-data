// FJ-J00060
// 100pts
#include <iostream>
#define int long long
using namespace std;
int n, res = 0;
pair<int, char> p[200005];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	bool f = true;
	for (int i = 0; i < n; ++i) {
		cin >> p[i].first >> p[i].second;
		if (i != 0 && p[i].second != p[i - 1].second) {
			f = false;
		}
	}
	if (f) {
		cout << 0;
		return 0;
	}
	int L = 0, R = n - 1;
	while (L < R) {
		if (p[L].second == p[R].second) {
			if (p[L].first < p[R].first) {
				p[R].first -= p[L].first;
				p[L].first = 0;
			} else if (p[L].first == p[R].first) {
				p[L].first = 0;
				p[R].first = 0;
			} else {
				p[L].first -= p[R].first;
				p[R].first = 0;
			}
		} else {
			if (p[L].first < p[R].first) {
				p[L].second = p[R].second;
				res += p[L].first;
			} else {
				p[R].second = p[L].second;
				res += p[R].first;
			}
		}
		if (p[R].first == 0) {
			--R;
		}
		if (p[L].first == 0) {
			++L;
		}
	}
	cout << res;
	return 0;
}
