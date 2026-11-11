#include <bits/stdc++.h>
using namespace std;

struct node {
	int real, g;
};

bool cmp(node a, node b) {
	return a.g > b.g;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	vector<node> a(n);
	vector<int> cnt(35);
	
	for (int j = 0; j < n; j++) {
		cin >> a[j].real;
		a[j].g = a[j].real;
		for (int i = 0; i < 32; i++) {
			if (a[j].real & (1 << i)) cnt[i]++;
		}
	}
	
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 32; i++) {
			if (a[j].real & (1 << i) && cnt[i] < m) {
				a[j].g -= 1 << i;
			}
		}
	}
	
	sort(a.begin(), a.end(), cmp);
	
	int ans = a[0].real;
	for (int i = 1; i < m; i++) {
		ans &= a[i].real;
	}
	
	cout << ans;
	
	return 0;
}
