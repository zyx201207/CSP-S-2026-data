#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5e5 + 10;

int n;
ll m;
ll a[N], sum[N];

bool check(int l, int r) {
	return (r - l + 1) * a[r] - sum[r] + sum[l - 1] <= m;
}

int fd(int x, int y) {
	int l = x, r = y;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid, y)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++) a[i] -= a[1], sum[i] = sum[i - 1] + a[i];
	
	int res = 0;
	for (int i = n; i >= 1; i --) {
		int l = fd(1, i);
		res = max(res, i - l + 1);
	}
	printf("%d", res);
	
	return 0;
} 
