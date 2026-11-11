#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, char>
#define fi first
#define se second
using namespace std;
ll n, ans = 0;
pii s[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s[i].fi >> s[i].se;
	}
	ll l = 1, r = n;
	while(l < r){
		ll mx, mn;
		mx = max(s[l].fi, s[r].fi);
		mn = min(s[l].fi, s[r].fi);
		if(s[l].se == s[r].se){
			s[l].fi -= mn;
			s[r].fi -= mn;
		}
		else{
			s[l].fi -= mn;
			s[r].fi -= mn;
			ans += mn;
		}
		if(s[l].fi == 0){
			l++;
		}
		if(s[r].fi == 0){
			r--;
		}
	}
	cout << ans;
	return 0;
}
