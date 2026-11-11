#include<bits/stdc++.h> 
#define fstio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
ll n, m, ans = -1;
ll a[N], c[N], sc[N], s[N];

ll sum(ll l, ll r){return (sc[r - 1] - sc[l - 1]) - (l - 1) * (s[r - 1] - s[l - 1]);}

int main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	fstio; cin >> n >> m;
	for (ll i = 1; i <= n; i ++) cin >> a[i]; sort(a + 1, a + 1 + n);
	for (ll i = 1; i <= n - 1; i ++) c[i] = a[i + 1] - a[i];
	for (ll i = 1; i <= n - 1; i ++) sc[i] = sc[i - 1] + c[i] * i, s[i] = s[i - 1] + c[i];

	
	for (ll t = 1; t <= n; t ++){
		ll l = 1, r = t;
		while (l < r){
			ll mid = (l + r) >> 1;
			if (sum(mid, t) < m) r = mid;
			else if (sum(mid, t) == m){l = r = mid; break;}
			else l = mid + 1;
		}
		ans = max(ans, t - l + 1);
	}
	cout << ans;
		
	return 0;
}
