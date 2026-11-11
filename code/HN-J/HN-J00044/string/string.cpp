#include <iostream>
#include <vector> 
#include <utility>
#include <math.h>

#define int long long

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	scanf("%d", &n);
	std::vector<std::pair<int, char>> vec(n);
	for (int i = 0; i < n; i++) scanf("%d %c", &vec[i].first, &vec[i].second);
	
	int result = 0;
	
	int l = 0, r = n-1;
	while (l < r) {
		int _tmp = std::min(vec[l].first, vec[r].first);
		
		if (vec[l].second != vec[r].second) result += _tmp;
		vec[l].first -= _tmp, vec[r].first -= _tmp;
		
		if (vec[l].first == 0) l++;
		if (vec[r].first == 0) r--;
	}
	
	printf("%lld\n", result);
	return 0;
}
