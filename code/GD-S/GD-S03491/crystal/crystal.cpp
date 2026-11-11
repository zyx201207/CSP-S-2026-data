#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n, m, a[N], pc[N], ans = 1;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	pc[1] = 0;
	for(int i = 2; i <= n; i++){
		pc[i] = pc[i - 1] + (a[i] - a[i - 1]) * (i - 1);
		ll cnt = i;
		if (pc[i] > m){
			ll l = 1, r = i - 1, mid;
			bool fd = 0;
			while (l < r){
				mid = (l + r) / 2;
				if (pc[i] - pc[mid] - mid * (a[i] - a[mid]) <= m){
					fd = 1;
					r = mid - 1;
				}
				else
					l = mid + 1;
			}
			if (!fd)
				continue;
			cnt = i - r - 1;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}

