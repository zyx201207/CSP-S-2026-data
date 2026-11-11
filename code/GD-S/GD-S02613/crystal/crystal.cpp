#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<long long>& nums, long long m, int g) {
	long long sum = 0;
	for (int i = 0; i < g - 1; i++) sum += nums[i];
	for (int i = g - 1; i < nums.size(); i++) {
		long long k = nums[i] * g;
		sum += nums[i];
		if (k - sum <= m) return true;
		sum -= nums[i + 1 - g];
	}
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;
	long long m;
	cin >> n >> m;
	vector<long long> nums(n);
	for (long long& x : nums) cin >> x;
	sort(nums.begin(), nums.end());
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(nums, m, mid)) l = mid + 1;
		else r = mid;
	}
	cout << r - 1;
	return 0;
}
