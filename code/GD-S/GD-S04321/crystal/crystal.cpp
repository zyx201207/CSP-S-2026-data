#include<bits/stdc++.h>
#define ll long long
#define N 500010


using namespace std;
ll n, m, ans, sum;
ll s[N], a[N];
//why?
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	//for(ll i = 1; i <= n; ++i)cout << a[i] << " ";
	a[0] = a[1];
	for(ll i = 1; i <= n; ++i){
		s[i] = a[i] - a[i - 1];
	}
	ll l = 1, cnt = 0;
	for(ll r = 2; r <= n; ++r){
		while(cnt + s[r] * (r - l) > m && l < r){
			cnt -= sum;
			if(cnt < 0) cnt = 0;
			sum -= s[l];
			l++;
		}
		ans = max(ans, r - l + 1);
		sum += s[r];
		cnt += s[r] * (r - l);
	}
	if(ans < 1) ans = 1;
	cout << ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
*/
