#include<bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> c;
long long adds[0x3f3f3f] = {};

long long result (long long idx) {
	long long ans = 1;
	long long ops = m;
	for (int i = idx - 1; i >= 0; --i) {
		if (c[idx] - c[i] > ops) {
			break;
		}
		ops -= c[idx] - c[i];
		ans++;
	}
	return ans;
}

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for(long long i = 1; i <= n; ++i) {
		long long x;
		cin >> x;
		c.push_back(x);
	}
	sort(c.begin(), c.end());
	 
	long long ans = 0;
	for (long long i = 1; i < n; ++i) {
		ans = max(ans, result(i));
	}
	cout << ans;
	return 0;
}
