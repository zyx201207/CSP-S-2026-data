#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500001], sum[300001];
bool vis[300001];
stack<int> lcc; //写暴力模拟吧，预估O(n^2*m)，拿前十二个点有点玄 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		for (int j = i; j < n; j ++) {
			while (! lcc.empty() && lcc.top() != a[j] && vis[a[j]]) {
				vis[lcc.top()] = false;
				lcc.pop();
			}
			if (! lcc.empty() && lcc.top() == a[j]) {
				lcc.pop();
			}
			lcc.push(a[j]);
			vis[a[j]] = true;
		}
		while (! lcc.empty()) {
			vis[lcc.top()] = true;
			++ sum[lcc.top()];
			lcc.pop();
		}
		memset(vis, false, sizeof(vis));
	}
	for (int i = 1; i <= m; i ++) {
		cout << sum[i] << " ";
	}
	cout << endl;
	return 0;
}
