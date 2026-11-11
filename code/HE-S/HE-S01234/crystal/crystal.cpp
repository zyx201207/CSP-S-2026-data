/*
5 5
1 2 4 8 9

3
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

long long n, m, ans = 0, a[N];

int get_12(long long a[]) {
	int ans = 1;
	priority_queue<int> lastAns;
	for (int i_3 = 0; i_3 <= n - 1; i_3++) {
		if (a[i_3] == a[i_3 + 1]) {
			ans += 1;
		}
		else {
			lastAns.push(ans);
			ans = 1;
		}
	}
	return lastAns.top();
}

long long startWork(long long a[], int start, long long m) {
	int ans = 1;
	for (int i = start; i <= n - 1; i++) {
		if (m <= 0) break;
		if (a[i] < a[i + 1]) {
			a[i] += 1;
			m -= 1;
			int getValue = get_12(a);
			ans = max(ans, getValue);
			i = start;
			continue;
		}
	}
	return ans;
}

int main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 0; i <= n - 1; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);
	
	for (int i = 0; i <= n - 2; i++) {
		ans = max(ans, startWork(a, i, m));
	}
	
	cout << ans << endl;
}
