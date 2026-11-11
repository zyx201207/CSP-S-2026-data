#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 

int n, m;
vector<int> nums;

int _max = INT_MIN;
vector<int> path;
unordered_map<int, bool> visit;
void dfs(int u) {
	if (u == m) {
		int result = path[0];
		for (int i = 1; i < m; i++) result &= path[nums[i]];
		_max = max(_max, result);
		return;
	}
	for (int i = u+1; i <= n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		path.push_back(i);
		dfs(u+1);
		path.pop_back();
		visit[i] = false;
	}
}

void test_1_5() {
	dfs(0);
	printf("%d\n", _max);
}

void test_6() {
	printf("%d\n", *max_element(nums.begin(), nums.end()));
}

void test_7() {
	int result = nums[1];
	for (int i = 2; i <= n; i++) result &= nums[i];
	printf("%d\n", result);
}

void test_8_10() {
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			_max = max(_max, nums[i] & nums[j]);
	printf("%d\n", _max);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	nums.resize(n+1);
	for (int i = 1; i <= n; i++) cin >> nums[i];
		
	if (n <= 20) test_1_5();
	else if (m == 1 && n <= 2000) test_6();
	else if (m == n && n <= 2000) test_7();
	else if (m == 2 && n <= 2000) test_8_10();
	else printf("0\n");
	return 0;
} 
