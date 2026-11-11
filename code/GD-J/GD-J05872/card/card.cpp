#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 5 * 1e5 + 5;

deque<int> p;

int f[kMaxN], ps[kMaxN];
int ans[kMaxN];
int n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> ps[i];
	for (int j = 1; j <= n; j ++) {
		memset(f, 0, sizeof(f));
		for (int i = j; i <= n; i ++) {
			int x = ps[i];
			if (f[x] == 0) {
//				printf("Push the card %d\n", x);
				f[x] = 1;
				p.push_front(x);
			} else {
				while (p.front() != x && !p.empty()) {
//					printf("Pop the card %d\n", p.front());
					f[p.front()] = 0;
					p.pop_front();
				}
//				printf("Pop the card %d\n", p.front());
//				printf("Push the card %d\n", x);
			}
		}
		while (!p.empty()) {
			ans[p.front()] ++;
			p.pop_front();
		}
//		cout << "\n";
//		for (int i = 1; i <= m; i ++) cout << ans[i] << "\n";
//		cout << "-----------------\n";
	}
	
//	cout << m;
	for (int i = 1; i <= m; i ++) cout << ans[i] << " ";
	return 0;
}
