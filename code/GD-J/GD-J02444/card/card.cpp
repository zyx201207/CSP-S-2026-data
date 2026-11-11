#include <iostream>
#include <stack>
using namespace std;

const int M = 8e5;
int n, m, a[M], ans[M];
stack <int> s;
bool vis[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (vis[a[j]]) {
				while (s.top() != a[j]) {
					vis[s.top()] = false;
					s.pop();
				}
			} else {
				s.push(a[j]);
				vis[a[j]] = true;
			}
		}
		while (!s.empty()) {
			ans[s.top()]++;
			vis[s.top()] = false;
			s.pop();
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
} 
