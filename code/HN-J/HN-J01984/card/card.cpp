#include <bits/stdc++.h>

using namespace std;

const int N = 501000;

int n, m, a[N];
set<pair<int, int>> st;
vector<pair<int, int>> e;
long long ans[N];
int flag[N], s[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ans[a[i]] += i;
	}
	for (int i = n; i >= 1; i--) {
		if (flag[a[i]]) {
			int l = i, r = flag[a[i]] - 1;
			auto p = st.lower_bound(make_pair(l - 1, 0));
			int minn = l, maxn = r;
			if (!st.empty() && (*p).second > l) {
				s[l] += i;
				s[(*p).second] -= i;
			}
			for (int j = 1; p != st.end() && (*p).second - 1 <= r; p++, j++) {
				auto t = p;
				if (j > 1 && t != st.begin()) {
					t--;
					s[(*t).first + 1] += i;
					s[(*p).second] -= i;
				}
				e.push_back((*p));
				minn = min(minn, (*p).second);
				maxn = max(maxn, (*p).first);
			}
			if (!st.empty() && (*p).first < r) {
				s[(*p).first + 1] += i;
				s[r + 1] -= i;
			}
			for (auto j : e) {
				s[j.second] -= i;
				s[j.first + 1] += i; 
				st.erase(j);
			}
			if (e.empty()) {
				s[minn] += i;
				s[maxn + 1] -= i;
			}
			st.insert(make_pair(maxn, minn));
			e.clear();
		}
		flag[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) s[i] += s[i - 1];
	for (int i = 1; i <= n; i++) ans[a[i]] -= s[i];
	for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
	puts("");
	return 0;
}
