#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxn = 2e6 + 5;

bool cmp(int x, int y) {
	return x < y;
}

long long n, m, a[maxn], b[maxn], index, ddd, mm = -1;
int delta = -114514;
bool f1 = true, f2 = true;

void solve1() {
	long long sum = 1;
	for (long long i = 1; i <= m; i += sum) {
		sum ++;
	}
	if (sum >= n) cout << n << endl;
	else cout << sum << endl; 
}

void solve2() {
	long long sum = delta, ans = 1;
	for (long long i = delta; i <= m; i += sum) {
		sum += delta; ans ++;
	}
	if (ans >= n) cout << n << endl;
	else cout << ans << endl; 
}

void solve3() {
	for (long long i = 1; i < n; i++) {
		b[i] = a[i + 1] - a[i];
	}
	long long cnt = 0, sum = 0, ans = -1;
	for (long long i = 0; i < n; i++) {
		for (long long j = i + 1; j < n; j++) {
			sum += b[j] * (j - i);
			if (sum > m) break;
//			cout << i << " " << j << endl;
			cnt++;
		}
		ans = max(ans, cnt);
		cnt = 0, sum = 0;
	}
	if ((ans + 1) >= n) cout << n << endl;
	else cout << ans + 1 << endl;
}

void solve4() {
	for (long long i = 1; i < n; i++) {
		b[i] = a[i + 1] - a[i];
		if (b[i] <= b[i - 1]) ddd++;
		else ddd = 0;
		if (ddd >= mm) {
			mm = ddd;
			index = i - ddd;
		}
	}
	long long cnt = 0, sum = 0, ans = -1;
	for (long long j = index; j < n; j++) {
		sum += b[j] * (j - index);
		if (sum > m) break;
//			cout << i << " " << j << endl;
		cnt++;
	}
	if (sum < m) {
		for (long long j = index - 1; j > 0; j--) {
			int ccc = 1;
			for (long long i = j; i <= index; i++) {
				sum += b[i] * ccc;
				ccc++;
			}
			if (sum > m) break;
	//			cout << i << " " << j << endl;
			cnt++;
		}
	}
	ans = max(ans, cnt);
	if ((ans + 1) >= n) cout << n << endl;
	else cout << ans + 1 << endl;
}
int main() {
	freopen("crystal3.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 2) delta = a[2] - a[1];
		if (a[i] != i) f1 = false;
		if (delta != a[i] - a[i - 1] && i > 2) f2 = false;
	}
	if (f1) {solve1(); return 0;}
	if (f2) {solve2(); return 0;}
	sort(a + 1, a + n + 1, cmp);
	solve3();
}
