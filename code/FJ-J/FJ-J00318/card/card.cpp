#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], ans[N];
bool f[N];
deque<int> q;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		memset(f, 0, sizeof(f));
		for (int j = i; j <= n; j++) {
			if (f[a[j]]) {
				while (q.back() != a[j]) {
					f[q.back()] = false;
					q.pop_back();
				}
			} else {
				q.push_back(a[j]);
				f[a[j]] = true;
			}
		}
		
		while (!q.empty()) {
			ans[q.front()]++;
			q.pop_front();
		}
	}
	
	for (int i = 1; i <= m; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
