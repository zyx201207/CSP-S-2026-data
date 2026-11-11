#include <cstdio>
#include <algorithm>
#include <climits>
#include <queue>
#include <functional>

using namespace std;

typedef long long ll;

ll n, m;

// non-rolling
ll dp[2005][2005];
void work1() {
	dp[0][0] = LLONG_MAX;
	for (int i = 1; i <= n ; i ++) {
		ll a = 0;
		scanf("%lld", &a);
		for (int j = 1 ; j <= m ; j ++) {
			dp[i][j] = max(dp[(i-1)][j], dp[(i-1)][j-1]&a);
//			printf("%lld ", dp[i][j]);
		}
//		putchar('\n');
	}
	printf("%lld", dp[n][m]);
}

void work2() {
	ll sum = LLONG_MAX;
	for (int i = 0 ; i < n ;i  ++) {
		ll a = 0;
		scanf("%lld", &a);
		sum &= a;
	}
	printf("%lld", sum);
}

void work3() {
	ll sum = 0;
	for (int i = 0 ; i < n ;i  ++) {
		ll a = 0;
		scanf("%lld", &a);
		sum = (sum > a ? sum : a);
	}
	printf("%lld", sum);
}

ll a[200005];
void work4() {
	ll sum = 0;
	for (int i = 0 ; i < n ;i  ++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0 ; i < n ; i ++) {
		for (int j = 0 ; j < i ; j ++) {
//			printf("%lld %lld %lld\n", a[i], a[j], a[i] & a[j]);
			if ((a[i] & a[j]) > sum) {
				sum = a[i] & a[j];
			}
		}
	}
	printf("%lld", sum);
}

void work5() {
	priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
	for (int i = 0 ; i < n ; i ++) {
		pq.push(a[i]);
		if (pq.size() > m) pq.pop();
	}
	printf("%lld", pq.top());
}

void work6() {
	ll res = LLONG_MAX;
	for (int i = 1 ; i <= m ; i ++) {
		res &= n-i;
	}
	printf("%lld", res);
}

ll b[4];

void work7() {
	for (int i = 0 ; i < n ; i ++) {
		b[a[i]]++;
	}
	if (b[3] >= m) puts("3");
	else if (b[3] + b[2] >= m) puts("2");
	else if (b[3] + b[1] >= m) puts("1");
	else puts("0");
}

ll dfs(ll pos, ll m, ll best, ll curr) {
	if (curr <= best) return best;
	if (pos > n) return 0;
	if (m <= 0) return curr;
	ll lhs = dfs(pos+1, m, best, curr);
	return dfs(pos+1, m-1, lhs, curr & a[pos]);
}

void work8() {
	printf("%lld", dfs(0, m, 0, LLONG_MAX));
}

void schedule() {
	bool spa = true, spb = ((n&(n-1)) == 0), sma = true;
	for (ll i = 0 ; i < n ; i ++) {
		scanf("%lld", &a[i]);
		if ((a[i]+1) & (a[i])) spa = false;
		if (a[i] != i) spb = false;
		if (a[i]>=4) sma = false;
	}
	if (spa) work5();
	else if (spb) work6();
	else if (sma) work7();
	else if (n <= 20) work8();
	else work1();
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	if (n == m) work2();
	else if (1 == m) work3();
	else if (2 == m) work4();
	else schedule();
	return 0;
}
