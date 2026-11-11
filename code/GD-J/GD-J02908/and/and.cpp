#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
long long c[N];
set<int> v[35];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 30; j++)
			if ((c[i] >> j) & 1)
				v[j].insert(i);
	for (int i = 30; i >= 0; i--) {
		if (v[i].size() < m) continue;
		long long ans = (1 << i);
		set<int> s = v[i];
		bool flag = true;
		for (int j = i - 1; j >= 0; j--) {
			set<int> tmp = s;
			vector<int> tv;
			for (auto k = tmp.begin(); k != tmp.end(); k++) {
				if (!v[j].count(*(k))) tv.push_back(*(k));
			} for (int i : tv)
                tmp.erase(i);
			if (tmp.size() >= m) s = tmp, ans += (1 << j);
		} cout << ans << '\n';
		break;
	} return 0;
}
