#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[500005],b[500005],ans = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m = 0;
	string h;
	cin >> n >> h;
	if(h.size() >= 10){
		cout << n;
		return 0;
	}
	else{
		int len = h.size() - 1,x = 1;
		for(int i = len;i >= 0;i--){
			m += (h[i] - '0') * x;
			x *= 10;
		}
	}
	for(ll i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a + n);
	for(ll i = a[0] + 1;i <= a[n - 1];i++){
		ll x = 0;
		for(ll j = 0;j < n;j++){			
			if(i < a[j])break;
			b[x] = i - a[j];
			x++;
		}
		sort(b,b + x);
		ll w = m,an = 0;
		for(ll j = 0;j < x;j++){
			if(w - b[j] >= 0){
				an++;
				w -= b[j];
			}
			else break;
		}
		ans = max(ans,an);
	}
	cout << ans;
	return 0;
}
