#include<bits/stdc++.h>
using namespace std;
const int INF = 1e6 + 10;
struct Card{
	int id = 0, la = INF;
};
bool cmp(Card a, Card b) {
	return a.la > b.la;
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> order(n + 1, 0);
	vector<vector<int>> g(m + 5);
	vector<Card> last(m + 5);
	vector<int> ans(m + 5);
	bool A = true;
	for (int i = 1; i <= n; i++) {
		cin >> order[i];
		if(order[i] < order[i - 1]) {
			A = false;
		}
		g[order[i]].push_back(i);
	}
	if (A == true) {
		for (int i = 1; i <= m; i++) {
			int k = upper_bound(order.begin(), order.end(), i) - order.begin() - 1;
			cout << k << " ";
		}
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int las = g[i][g[i].size() - 1];
		last[i].id = i;
		last[i].la = las;
	}
	sort(last.begin(), last.end(), cmp);
	for (int i = 1; i <= n; i++) {
		int king = order[i];
		while (king != last[1].id) {
			ans[king]++;
			king = order[g[king][g[king].size() - 1] + 1];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
