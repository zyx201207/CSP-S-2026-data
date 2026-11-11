#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;
const int MAXM = 3e5 + 10;

int n, m, a[MAXN], lst[MAXM];
int ans[MAXM], cnt; int book[MAXM];
bool flag = false;

void solve1() {
	for (int i = 1; i <= m; ++i) {
		cout << lst[i] << ' ';
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i > 1 && a[i] > a[i - 1]) 
			flag = true;
		lst[a[i]] = i;
	}
	if (!flag) {
		solve1();
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		stack<int> p;
		for (int j = i; j <= n; ++j) {
			if (book[a[j]] == i) {
				while (!p.empty() && p.top() != a[j]) {
					book[p.top()] = 0;
					p.pop();
				}
			} 
			else {
				book[a[j]] = i;
				p.push(a[j]);
			}
		}
		while (!p.empty()) {
			++ans[p.top()]; p.pop();
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}