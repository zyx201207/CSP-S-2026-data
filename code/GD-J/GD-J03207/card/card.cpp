//40 pts
#include<bits/stdc++.h>
using namespace std;
//#define ll long long
//#define pii pair<int,int>
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7; //998244353
int n, m, id = 0;
int a[500005], cnt[300005], vis[300005], lst[300005];
bool specialA = true;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		lst[a[i]] = i;
		if (i == 1) continue;
		if (a[i] < a[i - 1]) specialA = false;
	}
	if (specialA) {
		for (int i = 1; i <= m; i++) {
			cout << lst[i];
			if (i != m) cout << ' ';
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		++id;
		vector<int> deck;
		for (int j = n - i + 1; j <= n; j++) {
			if (vis[a[j]] != id) {
				vis[a[j]] = id;
				deck.push_back(a[j]);
			} else {
				bool rem = false;
				while (!rem) {
					int will_rem = deck[deck.size() - 1];
					if (will_rem == a[j]) rem = true;
					vis[will_rem] = 0;
					deck.pop_back();
				}
				deck.push_back(a[j]);
				vis[a[j]] = id;
			}
		}
		for (int t : deck) {
			cnt[t]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i];
		if (i != m) cout << ' ';
	}
	return 0;
}
