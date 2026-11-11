#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
int a[maxn];
vector <int> fail[32];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	set <int> st;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st.insert(i);
		for (int j = 0; j < 30; j++) if (!(a[i] & (1 << j))) fail[j].push_back(i);
	}
	ll ans = 0;
	for (int j = 29; j >= 0; j--) {
		set <int> nst = st;
		for (int x : fail[j]) nst.erase(x);
		if (nst.size() >= m) ans += (1ll << j), st = nst; 
	}
	cout << ans << "\n";
	return 0;
}

