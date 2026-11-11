
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 5e5 + 5;
ll a[M];
ll f[M];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if(n > 5000){
		for(int i = 2; i <= n; i++){
			f[i] = f[i - 1] + (a[i] - a[i - 1]);
		}
	}
	else{
		for(int i = 2; i <= n; i++){
			for(int j = 1; j < i; j++){
			f[i] += a[i] - a[j];
			}
		}
	}
	long long ans = 1;
	for(int i = 1; i <= n; i++){
		if(f[i] <= m){
			ans = i;
		}
	}
	ll l = 0, r = n;
	while(l < r){
		ll mid = (r - l + 1) / 2 + l;
		if(f[mid] <= m){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	ll k = m - f[l];
	if(k > 0 && l == n){
		cout << l - 1 << "\n";
	}
	else{
		cout << l << "\n";
	}
	return 0;
}

