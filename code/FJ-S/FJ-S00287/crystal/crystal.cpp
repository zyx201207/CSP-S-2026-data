#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[500002], s[500002], ans;
bool check(ll l, ll i) {
	return (i - l + 1) * a[i] - (s[i] - s[l - 1]) <= m;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
	for (ll i = 1; i <= n; i ++ ) {
		ll l = 1, r = i - 1, res = i;
		while (l <= r) {
			ll mid = l + r >> 1;
			if (check(mid, i)) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans;
}
//14.36

/*
3 2 1
wake up

human games
still learning how to play
but I guess I'm doing super great
(Am I super great? I'm super great)
blinking red

I take it all too hard it's ingraind(it's in my vein)
hello I'm a I'm a
1% battery girl
got one bar left in my blood
When I go around by the metro
grab the strap and wobble-wobble
1% battery girl
4 expressos just to go
oh just to go
life goes on
I need charge
take me somewhere quiet no one care
I need charge
if you need it too
I wouldn't mind staying with you
²ÝÐ´²»ÍêÁË 
*/ 
