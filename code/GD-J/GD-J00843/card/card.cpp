#include <bits/stdc++.h>
using namespace std;
int a[500005], c[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	queue<int> q, t, p;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		q.push(a[i]);
		p.push(a[i]);
	}
	for (int T = 1;T <= n;T++) {
		for (int i = T;i <= n;i++) {
			int tou = t.front();
			for (int j = 1; ;j++) {
				if (t.front() == q.front()) {
					while (t.front() != tou) {
						q.push(t.front());
						q.pop();
					}
					break;
				}else {
					t.push(t.front());
					t.pop();
				}
			}
		}
		int tl = t.size();
		for (int i = 0;i < tl;i++) {
			c[t.front()]++;
			t.pop();
		}
		while (!q.empty()) q.pop();
		for (int i = 1;i <= n;i++) {
			q.push(a[i]);
		}
	}
	for (int i = 0;i < m;i++) {
		cout << c[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);

return 0;}
