#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, card[N], ans[M], book[M];
bool b[M];
vector <int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}
	bool f = 0;
	for (int i = 1; i < n; i++) {
		if (card[i] > card[i + 1]) {
			f = 1;
			break;
		}
	}
	if (!f) {
		for (int i = 1; i <= n; i++) {
			ans[card[i]] = i;
		}
		for (int i = 1; i <= m; i++) cout << ans[i] << " ";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		a.clear();
		memset(book, 0, sizeof book);
		memset(b, 0, sizeof b);
		for (int j = i; j <= n; j++) {
			if (book[card[j]]) {
				while (a.size() && a[a.size() - 1] != card[j]) {
					book[a[a.size() - 1]]--;
					a.pop_back();
				}
			}
			else {
				a.push_back(card[j]);
				book[card[j]]++;
			}
		}
		for (int j = 0; j < a.size(); j++) {
			if (!b[a[j]]) ans[a[j]]++;
			b[a[j]] = 1;
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}

