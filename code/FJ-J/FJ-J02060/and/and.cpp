#include <bits/stdc++.h>
#define sp " "
#define el "\n"
#define r0 return 0
#define fi first
#define se second
#define F(i, a, b, c) for (int i = a; i <= b; i += c)

using namespace std;
typedef long long ll;
typedef string str;

int n, m;
bool a[200005][35];
int c[200005];
int ans = (1 << 30) - 1;
std::vector<int> v;

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	F(i, 1, n, 1) {
		cin >> c[i];
		int x = c[i];
		int cnt = 0;
		while (x) {
			if (x & 1) {
				a[i][cnt] = 1;
			}
			x /= 2, cnt++;
		}
	}
	int id = -1;
	F(j, 0, 30, 1) {
		int cnt = 0;
		F(i, 1, n, 1) {
			if (a[i][j]) {
				cnt++;
			}
		}
		if (cnt >= m) {
			id = j;
		}
	}
	if (id == -1) {
		cout << 0 << el;
		r0;
	}
	F(i, 1, n, 1) {
		if (a[i][id]) {
			v.push_back(c[i]);
		}
	}
	std::sort(v.begin(), v.end(), std::greater<int>());
	F(i, 0, m - 1, 1) {
		ans &= v[i];
	}
	cout << ans << el;
	r0;
}
