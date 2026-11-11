#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n), lst(m, -1), ans(m);
	for (int j = 0; j < n; j++) {
		cin >> a[j];
		lst[--a[j]] = j; 
	}
	vector<vector<int>> own(m);
	for (int j = 0; j < n - 1; j++) {
		own[a[j]].push_back(j);
		if (lst[a[j]] == j) {
			int x = a[j], y = a[j + 1];
			ans[x] = own[x].size();
			if (own[x].size() > own[y].size()) {
				swap(own[x], own[y]);
			}
			for (int i : own[x]) {
				own[y].push_back(i);
			}
			vector<int>().swap(own[x]);
		}
	}
	ans[a[n - 1]] = n;
	for (int x = 0; x < m; x++) {
		cout << ans[x] << ' ';
	}
	cout << '\n';
	
//	cerr << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
	return 0;
}

/*
好歌推荐：《纯爱战士 zrr》 

哦 zrr~ 你的爱情如此可惜~
未曾绽放，就毅然凋零~
哦 zrr~ 你却不曾知道~
你心心念念的他，在地球另一个方向~~~~~~ 
*/
