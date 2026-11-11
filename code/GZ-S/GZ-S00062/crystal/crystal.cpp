//GZ-S00062 ∏∂Í¿‘Û 
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vec vector
#define str string
#define fi first
#define se second
using namespace std;

const ll N = 5e5 + 5;

ll a[N], p[N];

bool check(ll x, ll i, ll m) {
	ll cnt = i - x + 1;
    ll sum = p[i] - p[x-1] + m;
    
    if(a[i] >= 0)
        return sum / cnt >= a[i];
    else return sum / cnt <= a[i];
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, m;
	cin >> n >> m;
	for(ll i = 1;i <= n;i++)
	    cin >> a[i];
    sort(a + 1, a + n + 1);

	for(ll i = 1;i <= n;i++)
        p[i] = p[i-1] + a[i];

    ll ans = 0;
    for(ll i = 1;i <= n;i++) {
        ll l = 0, r = i;
        while(l + 1 != r) {
            ll mid = (r - l) / 2 + l;
            (check(mid, i, m) ? r : l) = mid;
        }
        ans = max(ans, i - r + 1);
    }

    cout << ans << endl;

	return 0;
}

