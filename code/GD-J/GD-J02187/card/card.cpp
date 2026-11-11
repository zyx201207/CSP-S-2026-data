#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int n, m;
int a[N];
stack<int> s;
bool b[N];
int ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		while (!s.empty()) s.pop();
		memset(b, false, sizeof(b));
		for (int j = i; j <= n; j++) {
			if (b[a[j]]) {
				while (s.top() != a[j])
					b[s.top()] = false, s.pop();
			} else s.push(a[j]), b[a[j]] = true;
		}
		for (int i = 1; i <= m; i++)
			ans[i] += b[i];
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}
