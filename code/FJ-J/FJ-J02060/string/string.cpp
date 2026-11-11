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

int n;
int a[200005];
char s[100000005], c[200005];
int m = 0;

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	F(i, 1, n, 1) {
		cin >> a[i] >> c[i];
		F(j, 1, a[i], 1) {
			s[++m] = c[i];
		}
	}
	int ans = 0;
	F(i, 1, m / 2, 1) {
		if (s[i] != s[m - i + 1]) {
			ans++;
		}
	}
	cout << ans << el;
	r0;
}
