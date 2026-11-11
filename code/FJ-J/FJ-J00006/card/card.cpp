#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
const int M = 3e5 + 50;
int n, m, a[N], cnt[M];
bool vis[M];
void Sub1() {
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= m; i++) vis[i] = false;
		stack<int> s;
		for (int j = i; j <= n; j++) {
			if (!vis[a[j]]) {
				s.push(a[j]);
				vis[a[j]] = true;
				continue;
			}
			while (!s.empty() && s.top() != a[j]) {
				vis[s.top()] = false;
				s.pop();
			}
		}
		while (!s.empty()) {
			cnt[s.top()]++;
			s.pop();
		}
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] << ' ';
}
bool check() {
	for (int i = 1; i <= n; i++) 
		if (a[i + 1] > a[i]) return false;
	return true;
}
void Sub2() {
	for (int i = n; i >= 1; i--)
		if (!cnt[a[i]]) cnt[a[i]] = i;
	for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (check()) Sub2();
	else Sub1();
	fclose(stdin);
	fclose(stdout);
}
