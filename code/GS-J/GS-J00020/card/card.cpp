#include <bits/stdc++.h>
using namespace std;

int n, m, ans[300010] = {0};
vector<int> pd(500010), zm(500010);

int find_(int x) {
	for (int i = 1; i <= zm.size(); i++)
		if (zm[i] == x) return i;
	return -1;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> pd[i];
	
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= n; j++) {
			int pos = find_(pd[j]);
			if (pos == -1) zm.push_back(pd[j]);
			else {
				zm.erase(zm.begin() + pos, zm.end());
				zm.push_back(pd[j]);
			}
		}
		for (int j = 1; j <= zm.size(); j++) 
			if (1 <= zm[j] <= m) ans[zm[j]]++;
		zm.clear();
	}
	
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';	
	return 0;
}



/*
#include <bits/stdc++.h>
using namespace std;

int n, m, ans[300010] = {0};
vector<int> pd(500010), ans_(300010);

int main() {
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> pd[i];
	
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= n; j++) {
			if (ans_[pd[j]] != 0) {
				ans_[pd[j]] = 1;
				for (int y = j; y <= 100000; y++) ans_[y] = 0;
			}
			else ans_[pd[j]]++;
		}
	}
	
	for (int i = 1; i <= m; i++) cout << ans_[i] << ' ';	
	return 0;
}*/
