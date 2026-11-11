#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	fileIO("and");
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) cin >> a[i];
	
	int ans = 0;
	for(int j = 29; j >= 0; j --) {
		vector<int> b;
		for(int i = 0; i < a.size(); i ++)
			if((a[i] >> j) & 1) b.push_back(a[i]);
		if(b.size() >= m) {
			swap(a, b);
			ans ^= 1 << j;
		}
	} 
	cout << ans << "\n";
} 
