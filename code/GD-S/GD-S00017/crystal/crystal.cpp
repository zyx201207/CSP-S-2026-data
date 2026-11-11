#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	vector<long long> a;
	for(int i = 0; i < n; i++) {
		long long ai;
		cin >> ai;
		a.push_back(ai);
	}
	sort(a.begin(), a.begin() + n);
	long long ans = 0;
	for(long long i = 1; i < n; i++) {
		if(((a[i] - a[i - 1]) * i + ans) > m) {
			cout << i;
			break;
		} else {
			ans = (a[i] - a[i - 1]) * i + ans;
		}
	}
	return 0;
}
