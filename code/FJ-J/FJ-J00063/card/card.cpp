#include <bits/stdc++.h>
using namespace std;
int a[500005], cnt[300010];
bool InS(stack<int> s, int Q) {
	stack<int> ss = s;
	while(!ss.empty()) {
		if (ss.top() == Q) return 1;
		ss.pop();
	} 
	return 0;
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		stack<int> pd;
		for (int j = n - 1; j >= i; j--) {
			pd.push(a[j]);
		}
		
		stack<int> tab;
		
		while(!pd.empty()) {
			int k = pd.top();
			if (InS(tab, k)) {
				while (tab.top() != k) {
					tab.pop();
				}
				tab.pop();
			}
			tab.push(k);
			pd.pop();
		}
		
		while (!tab.empty()) {
			cnt[tab.top()]++; tab.pop();
		}
	}
	
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	cout << endl;
	return 0;
}
