#include <bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
bool is[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> h;
	for(int i = 1; i <= n; i++) {
		for(int k = i; k <= n; k++) {
			int p = a[k];
			for(auto it = h.begin(); it != h.end(); it++) {
				if(*it == p) {
					h.erase(it, h.end() - 1);
				}
			}
			h.push_back(p);
		}
		for(int j = 0; j < h.size(); j++) {
			is[h[j]] = true;
		}
		for(int j = 1; j <= m; j++) {
			cnt[j] += is[j];
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}

