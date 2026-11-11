#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10, M = 31;
int n, m, t, a[N], f[M + 1], ans;
vector<int> g[M + 1];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = M; j >= 0; j--) {
			if ((a[i] >> j) & 1) {
				f[j]++;
				g[j].push_back(a[i]);
			}
		}
	}
	
	for (int i = M; i >= 0; i--) {
		if (f[i] >= m) {
			t = i;
			break;
		}
	}
	
	sort(g[t].begin(), g[t].end());
	ans = g[t][(int)g[t].size() - 1];
	for (int i = g[t].size() - 2; i >= 0 && --m; i--) {
		ans &= g[t][i];
	} 
	
	printf("%d\n", ans);
	return 0;
}
