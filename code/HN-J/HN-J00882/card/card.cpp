#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

constexpr int MAXN = 5e5 + 10;
constexpr int MAXM = 3e5 + 10;

int n, m, a[MAXN], ans[MAXM], b[MAXN], head = 1, tail = 0, lst[MAXN];
vector<int> x;
bool is[MAXM];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	bool isis = true;
	for (register int i = 1; i <= n; ++i) {
		cin >> a[i], isis &= (a[i] >= a[i - 1]);
		if (a[i] != a[i - 1]) b[++tail] = i;
	}
	
	if (isis) {
		for (register int i = 1; i <= n; ++i) lst[a[i]] = i;
		for (register int i = 1; i <= m; ++i) cout << lst[i] << " \n"[i == m];
		return 0; 
	}
	
	for (register int i = 1; i <= n; ++i) {
		for (register int j = 1; j <= m; ++j) is[j] = false;
		x.clear(), is[a[i]] = true, x.push_back(a[i]);
		if (b[head] < i) ++head;
		
		for (register int jj = head; jj <= tail; ++jj) {
			int j = b[jj], d = a[j];
			if (is[a[j]]) {
				while (!x.empty() && x.back() != d) {
					int k = x.back();
					is[k] = false, x.pop_back();
				}
			} else is[d] = true, x.push_back(d);
		}
		
		for (int d : x) ++ans[d];
	}
	
	for (register int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i == m];
	return 0;
}
