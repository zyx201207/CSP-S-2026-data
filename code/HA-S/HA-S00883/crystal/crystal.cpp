#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int a[500005], answ, pre[500005];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++) pre[i] = a[i] + pre[i - 1];
	for(int i = 1;i <= n;i++) {
		int r = i - 1, l = 1;
		while(l <= r) {
			int mid = (l + r) / 2;
			int nee = (mid + 1) * a[i] - pre[i] + pre[i - mid - 1];
			if(nee <= m) l = mid + 1;
			else r = mid - 1; 
		}
		answ = max(answ, l);
	}
	cout << answ;
	return 0;
} 
