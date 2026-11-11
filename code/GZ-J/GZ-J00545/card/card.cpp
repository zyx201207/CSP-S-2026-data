// GZ-J00545 ∂≈‘ÛÏ” 
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 +5; 
int n, m;
vector<int> t(N);
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	vector<int> a(m + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<int> ans(n + 1, 0);
	for(int i = 1; i <= m; i ++) {
		t = {};
		queue<int> q;
		for(int j = i; j <= n; j ++) {
			q.push(a[j]);
			if(t[a[j]]) {
				for(int k = t[a[j]]; k <= q.size(); k ++) {
					q.pop();
					t[a[k]] = 0;
				}
			}
			t[a[j]] = min(t[a[j]], j);
		}
		for(int j = 1; j <= q.size(); j ++) {
			if(q.front() == i) {
				ans[i] ++;
				break;
			}
			q.pop();
		}
	}
	
	for(int i = 1; i <= m; i ++) {
		cout << ans[i] << " ";
	}
	return 0;
} 
