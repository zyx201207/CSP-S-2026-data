#include <bits/stdc++.h>
using namespace std;

struct pack {
	long long count;
	char flag;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n; 
	
	vector<pack> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i].count >> a[i].flag;
	}
	
	long long i = 0, j = n-1, ans = 0;
	while (i < j) {
		long long cnt = min(a[i].count, a[j].count);
		a[i].count -= cnt;
		a[j].count -= cnt;
		if (a[i].flag != a[j].flag) {
			ans += cnt;
		} 
		if (a[i].count == 0) i++;
		if (a[j].count == 0) j--;
	}
	
	cout << ans;
	
	return 0;
}
