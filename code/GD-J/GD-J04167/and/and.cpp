#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
long long m;
vector<long long> v[35];
long long maxx;
void dfs(long long sum, long long t, long long s) {
	if (s == m) {
		maxx = max(maxx, sum);
		return ;
	}
	for (int i = t + 1; i <= n; i++) {
		dfs(sum & a[i], i, s + 1);
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		long long t = a[i];
		for (int j = 0; j <= 30; j++) {
			if (t & 1) v[j].push_back(a[i]);
		}
	}
	for (int i = 31; i >= 1; i--) {
		if (v[i].size() >= m) {
			dfs((1 << 31) - 1, 0, 0);
			break;
		}
	}
	cout << maxx;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
