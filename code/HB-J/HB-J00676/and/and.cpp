#include <iostream>
#include <algorithm>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 2e5 + 5;
const int x = (1LL << 32) - 1;

int n, m, a[N];

bool check1() {
	return m == 1;
}

bool check2() {
	return m == n;
}

bool check3() {
	return n <= 2000 && m == 2;
}

bool check4() {
	F(i, 1, n) if ((x & a[i]) != x) return 0;
	return 1;
}

bool check5() {
	if ((x & (n - 1)) != x) return 0;
	F(i, 1, n) if (a[i] != i - 1) return 0;
	return 1;
}

bool check6() {
	F(i, 1, n) if (a[i] >= 4) return 0;
	return 1;
}

void solve1() {
	int ans = 0;
	F(i, 1, n) ans = max(ans, a[i]);
	cout << ans;
	return ;
}

void solve2() {
	int ans = x;
	F(i, 1, n) ans &= a[i];
	cout << ans;
	return ;
}

void solve3() {
	int ans = 0;
	F(i, 1, n) F(j, i + 1, n)
		ans = max(ans, a[i] & a[j]);
	cout << ans;
	return ;
}

void solve4() {
	sort(a + 1, a + n + 1, greater <int>());
	int ans = x;
	F(i, 1, m) ans &= a[i];
	cout << ans;
	return ;
}

void solve5() {
	cout << n - m;
	return ;
}

void solve6() {
	int ans, cnt[4];
	F(i, 1, n) cnt[a[i]]++;
	if (cnt[3] >= m) ans = 3;
	else if (cnt[3] + cnt[2] >= m) ans = 2;
	else if (cnt[3] + cnt[2] + cnt[1] >= m) ans = 1;
	else ans = 0;
	cout << ans;
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	F(i, 1, n) cin >> a[i];
	
	if (check1()) solve1();
	else if (check2()) solve2();
	else if (check3()) solve3();
	else if (check4()) solve4();
	else if (check5()) solve5();
	else if (check6()) solve6();
	
	return 0;
}
