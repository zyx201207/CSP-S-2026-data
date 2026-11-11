#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
#define ll long long

ll n, m, minn, maxn, ans = 1;
ll a[N], sum[N];
bool A = true;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(ll i = 2; i <= n; i++){
		A = A && (a[i] - a[i - 1] == a[2] - a[1]);
	}
	if(!A){
		sum[1] = a[1];
		minn = maxn = a[1];
		for(ll i = 2; i <= n; i++){
			sum[i] = sum[i - 1] + a[i];
			minn = min(minn, a[i]);
			maxn = max(maxn, a[i]);
		}
		for(ll i = minn; i <= maxn; i++){
			ll x = upper_bound(a + 1, a + n + 1, i) - (a + 1), y;
			ll l = 1, r = x, mid;
			while(l < r){
				mid = (l + r) / 2;
				if(i * (x - mid + 1) - (sum[x] - sum[mid - 1]) <= m){
					r = mid;
				}else{
					l = mid + 1;
				}
			}
			y = r;
			if(i * (x - y + 1) - (sum[x] - sum[y - 1]) <= m){
				ans = max(ans, x - y + 1);
			}
		}
		cout << ans;
	}else{
		for(int i = 1; i <= n; i++){
			if((a[n] - a[i]) * ((a[n] - a[i]) / (a[2] - a[1]) + 1) / 2 <= m){
				cout << n - i + 1;
				break;
			}
		}
	}
	return 0;
}
