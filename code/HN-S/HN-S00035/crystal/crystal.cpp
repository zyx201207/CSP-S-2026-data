#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	scanf("%lld%lld", &n, &m);
	std::vector<long long> vec(n, 0);
	std::vector<long long> pre(n, 0);
	for (int i = 0; i < n; i++) scanf("%lld", &vec[i]);

	std::sort(vec.begin(), vec.end());

	std::unordered_map<int, int> vals;
	for (int i = 0; i < n; i++) {
		if (i == 0) pre[i] = vec[i];
		else pre[i] = pre[i-1] + vec[i];
		vals[vec[i]]++;
	}

	int result = 1;
	for (long long i = 1; i < n; i++)
		if (i * vec[i] - pre[i-1] <= m) result = i+vals[vec[i]];
	printf("%d\n", result);
	return 0;
}
