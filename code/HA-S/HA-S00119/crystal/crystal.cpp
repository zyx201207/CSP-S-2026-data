

#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;

const int N = 500010;

int n;
long long m;
long long nums[N];
long long now;
long long res;
deque<long long> dq;

int main () {
	
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &(nums[i]));
	}
	sort (nums + 1, nums + 1 + n);
	
	for (int i = 1; i <= n; i++) {
		now += dq.size() * (nums[i] - nums[i - 1]);
		while (!dq.empty() && now > m) {
			now -= (nums[i] - dq.front());
			dq.pop_front();
		}
		dq.push_back(nums[i]);
		res = max (res, (long long) (dq.size()));
	}
	printf ("%lld\n", res);
	
	return 0;
}