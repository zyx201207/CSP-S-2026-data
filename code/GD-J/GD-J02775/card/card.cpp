#include<bits/stdc++.h>
using namespace std;
long long n, m;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	vector<long long>a(n), c(n), b(m);
	vector<pair<long long, long long>>tmp(n); 
	for (auto & i : c) cin >> i;
	for (int i = 0; i < n; i++) a[i] = c[i];
	for (long long i = 0; i < n; i++) {
		long long j = i, cnt = 0;
		for (long long J = i; J < n; J++) {
			tmp[c[J]].first++;
			if (tmp[c[J]].first > 1) {
				j = tmp[c[J]].second;
				a[j] = c[J];
				for (long long k = j + 1; k <= J; k++) a[k] = 0;
			} else tmp[c[J]].second = j;
			j++;
		}
		for (long long J = i; J < n; J++) {
			if (a[J] == i) b[i]++;
		}
		cout << b[i] << ' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
