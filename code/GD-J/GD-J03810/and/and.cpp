#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<unsigned> nums(n);
	for (unsigned &num : nums) {
		cin >> num;
	}
	
	vector<bool> flag(n);
	unsigned ans = 0;
	for (int i = 29; i >= 0; i--) {
		int cu_cnt = 0;
		for (int j = 0; j < n; j++) {
			if (flag[j]) continue;
			if ((nums[j] >> i) & 1) {
				cu_cnt++;
			}
		}
		if (cu_cnt >= m) {
			ans += 1 << i;
			for (int j = 0; j < n; j++) {
				if (flag[j]) continue;
				if (!((nums[j] >> i) & 1)) {
					flag[j] = true;
				}
			}
		}
	}
	cout << ans << endl;
}
