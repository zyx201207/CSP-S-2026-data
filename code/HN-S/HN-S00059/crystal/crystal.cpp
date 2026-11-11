/*
T1 还是会的

考虑二分答案，这答案显然有单调性

对于答案的判断，可以用滑动窗口 + 前缀和 

我看错题了，只能增加啊 
*/
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 10;
int n, m, a[N], s[N];

int get(int l, int r) {
	int len = r - l + 1;
	int sum = s[r] - s[l - 1];
	return len * a[r] - sum;
}

int check(int x) {
	for(int i = 1; i + x - 1 <= n; i++) {
		int r = i + x - 1; 
		int sum = get(i, r);
		if(sum <= m) return i;
	} return 0;
}

signed main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m; // fc crystal.out crystal.ans
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int l = 1, r = n, ans = 1;
	while(l <= r) {
		int mid = l + r >> 1;
		if(!check(mid)) r = mid - 1;
		else l = mid + 1, ans = mid; 
	} cout << ans; 
	return 0;
} 












