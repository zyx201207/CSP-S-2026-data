//GZ-S00165 遵义市第四中学 杨子腾 
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
#define ll long long
ll a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, ans = 0;
	ll m, s = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = n, j = n;i;i--) {
		while (j){
			ll t = a[i] - a[j];	
			if (s + t > m)break;
			s += t, j--;
		}
		ans = max(ans, i - j), s -= (a[i] - a[i - 1]) * (i - j);
	}
	cout << ans;
	return 0;
}
