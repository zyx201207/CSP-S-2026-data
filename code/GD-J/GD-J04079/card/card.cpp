#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], card[500005], card_size, ans[300005];
unordered_map<int, pair<bool, int> > card_kind;
void init() {
	memset(card, 0, sizeof(card));
	card_size = 0;
	card_kind.clear();
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		init();
		for (int j = i; j <= n; j++) {
			if (card_kind[a[j]].first) {
				for (int k = card_kind[a[j]].second; k <= card_size; k++)
					card_kind[card[k]] = make_pair(0, 0), card[k] = 0;
				card_size = card_kind[a[j]].second - 1;
			}
				card[++card_size] = a[j], card_kind[a[j]] = make_pair(1, card_size);
		}
		for (int j = 1; j <= m; j++) {
			if (card_kind[j].first)
				ans[j]++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}