#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Num {
	long long val;
	int len;
	int cnt1;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	vector<Num> nums(n + 1);
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		nums[i].val = x;
		
		int cnt1 = 0;
		int len = 0;
		while (x) {
			x /= 2;
			if (x % 2) {
				++cnt1;
			}
			++len;
		}
		nums[i].len = len;
		nums[i].cnt1 = cnt1;
	}
	
	sort(nums.begin() + 1, nums.end(), [](const Num& a, const Num& b) {
		return (a.len == b.len) ? a.cnt1 > b.cnt1 : a.len > b.len;
	});
	
	long long ans = LONG_LONG_MAX;
	for (int i = 1; i <= k; ++i) {
		ans &= nums[i].val;
	}
	
	cout << ans << endl;
	return 0;
}

