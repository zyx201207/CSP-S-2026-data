#include <iostream>
const int MAXN = 2e5 + 5;
using ll = long long;

int n, ans;
int a[MAXN]; ll s[MAXN];
char c[MAXN];

bool all1 = 1;
std::string str;

void solveall1() {
	for (int i = 1; i <= n; i++)
		str += c[i];
	for (int i = 1; i <= n; i++)
		if (str[i] != str[n - i + 1]) ans++;
	std::cout << ans << '\n';
}

int main() {
	std::freopen("string.in", "r", stdin);
	std::freopen("string.out", "w", stdout);
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i] >> c[i];
		s[i] = s[i - 1] + 1ll * a[i];
		all1 = all1 && (a[i] == 1);
	}
	if (all1) {
		solveall1();
		return 0;
	}
	ll tot = s[n] / 2, len = s[n];
	for (ll i = 1; i <= tot; i++) {
		char ch1, ch2;
		for (int j = 1; j <= n; j++)
			if (s[j - 1] < i && i <= s[j]) {
				ch1 = c[j];
				break;
			}
		ll cr = len - i + 1;
		for (int j = 1; j <= n; j++)
			if (s[j - 1] < cr && cr <= s[j]) {
				ch2 = c[j];
				break;
			}
		ans += (ch1 != ch2);
	}
	std::cout << ans << '\n';
	return 0;
}