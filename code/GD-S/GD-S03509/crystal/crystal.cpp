#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[500010], d[500010];

int check(int x) {
	int sum = 0, mn;
	for(int i = 1; i <= x; i++) {
		sum += d[x] - d[i];
	}
	mn = sum;
	for(int i = x + 1; i <= n; i++) {
		sum -= (d[i - 1] - d[i - x]);
		sum += (x - 1) * (d[i] - d[i - 1]);
		mn = min(mn, sum);
	}
	return mn <= m;
} 

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + (a[i] - a[i - 1]);
	}
	
	int l = 0, r = n + 1;
	while(l + 1 < r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << l << endl;
	
	return 0;
} 
