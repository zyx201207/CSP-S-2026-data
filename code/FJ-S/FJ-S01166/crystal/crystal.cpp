#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[(int)(5e5 + 1)];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crestal.out", "w", stdout);
	int n;
	ll m;
	bool flag = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != i) flag = 0;
	}
	if (flag){
		int l = 0, r = n, mid, ans;
		while (l <= r){
			mid = (l + ((r - l) >> 1));
			if ((mid * 1l * (mid + 1) / 2) <= m){
				l = (mid + 1);
				ans = (mid + 1);
			} else r = (mid - 1);
		}
		cout << ans;
		return 0;
	}
	sort((a + 1), (a + n + 1));
	int maxn = 0, cnt;
	ll sum;
	for (int i = 2; i <= n; i++){
		cnt = 1;
		sum = 0;
		for (int j = (i - 1); j; j--){
			sum += (a[i] - a[j]);
			if (sum > m) break;
			cnt++;
		}
		maxn = max(maxn, cnt);
	}
	cout << maxn;
}
