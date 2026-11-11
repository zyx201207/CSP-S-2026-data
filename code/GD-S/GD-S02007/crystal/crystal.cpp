#include<bits/stdc++.h>
using namespace std;
#define int long long //注意内存

//c++14
//多测清空
//边界
//复杂度

const int N = 5e5 + 5;

int a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum = 0, l = 1, ans = 1;
	for(int i = 1; i <= n; i++) {
		sum += (a[i] - a[i - 1]) * (i - l);
		while(sum > m && l < i) {
			sum -= (a[i] - a[l]);
			l++;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	
	return 0;
}
//I AK IOI

