#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n, ans;
ll m, a[N], sum[N];

bool check(int i, int j){
	ll s1 = a[i] * (i - 1 - j + 1);
	ll s2 = sum[j] - sum[i];
	return s1 - s2 <= m;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	for(int i = n; i >= 1; --i) sum[i] = sum[i + 1] + a[i];
	for(int i = 1; i <= n; ++i){
		int res = 0;
		int l = 1, r = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(i, mid)) res = max(res, i - mid + 1), r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, res);
	}
	cout << ans << '\n';
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 3
-9 0 9 16 28
*/
