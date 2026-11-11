#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
long long cnt[maxn], a[maxn], pre[maxn];
bool check(int x);
long long n, m;
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" ,"w" , stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for (int i = 1 ; i <= n ; i ++) pre[i] = pre[i - 1] + a[i];
	int l = 1 , r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}
bool check(int x) {
	long long allcost = 1e18;
	for (int j = x ; j <= n ; j ++) {
		int i = j - x + 1;
		allcost = min(allcost, (a[j] * x) - (pre[j] - pre[i - 1]));
	}
	return allcost <= m;
}
