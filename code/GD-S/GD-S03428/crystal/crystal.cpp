#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for (long long &i : a) {
		cin >> i;
	}
	
	sort(a.begin(), a.end());
	
	deque<long long> win;
	long long sum = 0;
	int ans = 0;
	long long lstwei = 0;
	for (int i = 0; i < n; i++) {
		sum += (a[i] - lstwei) * win.size();
		lstwei = a[i];
		win.push_back(i);
		while (sum > m) {
			sum -= a[win.back()] - a[win.front()];
			win.pop_front();
		}
		ans = max(ans, (int)win.size());
	}
	cout << ans << endl;
}
