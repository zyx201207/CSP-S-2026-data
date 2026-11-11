#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
pair <int, char> a[N];
//string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	cin >> n;
	for (int i=1; i<=n; i++) 
		cin >> a[i].first >> a[i].second;
	long long sum = 0;
	int l = 1, r = n;
	while (l <= r) {
		if (a[l].second != a[r].second) 
			sum += min(a[l].first, a[r].first);
		if (a[l].first < a[r].first) {
			a[r].first -= a[l].first;
			l++;
		} else {
			a[l].first -= a[r].first;
			r--;
		}
	}
	cout << sum;
//	cout << s;
	return 0;
}
/*
2 a
2 b
1 c

aabbc

cabbc
*/
