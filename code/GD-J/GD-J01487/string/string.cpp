#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long w;
	char c;
	long long count = 0;
	vector<int> v(5e9, 0);
	
	for (int i = 1; i <= n; i++) {
		cin >> w >> c;
		for (long long j = 1; j <= w; j++) {
			v[count + j] = int(c);
		}
		count += w;
	}
	long long ans = 0;
	for (long long i = 1; i <= (count + 1) / 2; i++) {
		if (v[i] != v[count + 1 - i]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
} 
