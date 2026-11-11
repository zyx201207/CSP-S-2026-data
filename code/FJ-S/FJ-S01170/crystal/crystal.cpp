#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n, ans;
ll m, a[N], sum[N];
bool check(int x, int k){
	ll res = a[k] * (k - x + 1) - (sum[k] - sum[x - 1]);
	return m >= res;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n;i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1;i <= n;i++){
		int l = 1, r = i;
		while(l <= r){
			int mid = l + r >> 1;
			if (check(mid, i)){
				ans = max(ans, i - mid + 1);
				r = mid - 1;
			}
			else l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
