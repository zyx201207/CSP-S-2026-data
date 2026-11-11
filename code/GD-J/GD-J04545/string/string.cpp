#include <bits/stdc++.h>
using namespace std;
vector<pair<int, char>> znb;

int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		znb[i].first = a;
		znb[i].second = c;
		sum += a;
	}
	long long l = calc(sum / 2);
	cout << l;
	return 0;
}
