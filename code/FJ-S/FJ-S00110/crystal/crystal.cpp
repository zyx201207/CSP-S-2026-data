#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
ll a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	scanf("%lld%lld", &n, &m);
	for (int i = 0 ; i < n ; i ++) {
		scanf("%lld", &a[i]);
	}
	std::sort(a, a+n);
	std::queue<ll> q;
	ll mx = 1, cost = 0;
	q.push(0);
	for (int i = 1 ; i < n ; i ++) {
		ll ncostd = q.size() * (a[i]-a[i-1]);
		while (cost + ncostd > m && !q.empty()) {
			if (mx < q.size()) mx = q.size();
			ncostd -= a[i] - a[q.front()];
			q.pop();
		}
		q.push(i);
		cost += ncostd;
	}
	printf("%lld\n", mx);
	return 0;
}
