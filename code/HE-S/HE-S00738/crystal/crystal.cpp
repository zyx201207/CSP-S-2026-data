#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, a[N], m, pre[N], An;
int er(int i) {
	int L = 1, R = i, ans = i;
	while(L <= R) {
		int mid = L + R >> 1;
		int sum = (i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]);
		if(sum <= m) ans = mid, R = mid - 1;
		else L = mid + 1;
	}
	return i - ans + 1;
}
signed main() {
//	freopen("D:\\P.in", "r", stdin);
//	freopen("D:\\P.out", "w", stdout);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i];
	for(int i = 1; i <= n; i ++) {
		An = max(An, er(i));
	}	
	cout << An;
	return 0;
}
 
