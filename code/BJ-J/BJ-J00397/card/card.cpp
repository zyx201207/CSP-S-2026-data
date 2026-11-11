#include <iostream>
#include <cstring>
const int MAXN = 5e5 + 5, MAXM = 3e5 + 5;

int n, m;
int a[MAXN];
int stk[MAXN], top;
bool in_stk[MAXM];

int ans[MAXM];

int main() {
	std::freopen("card.in", "r", stdin);
	std::freopen("card.out", "w", stdout);
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int cur = i; cur <= n; cur++) {
			if (!in_stk[a[cur]]) {
				stk[++top] = a[cur];
				in_stk[a[cur]] = 1;
			} else {
				while (top) {
					int k = stk[top];
					if (k == a[cur]) break;
					top--, in_stk[k] = 0;
				}
			}
		}
		for (int j = 1; j <= n; j++)
			ans[j] += in_stk[j];
		top = 0;
		std::memset(in_stk, 0, sizeof(in_stk));
	}
	for (int i = 1; i <= m; i++)
		std::cout << ans[i] << ' ';
	std::cout << '\n';
	return 0;
}

// i love 3 forever