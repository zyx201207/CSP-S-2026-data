#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100007

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

	freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	
    ll n, m; cin >> n >> m; ll a[maxn] = {0}, f[maxn] = {0};
//  vector<ll> sum = a; accumulate(sum.begin(), sum.end());


    for (ll i=1;i<=n;i++)
    {
        cin >> a[i];
    } sort(a+1, a+n+1); a[0] = 0;

    for (int i=1;i<=n;i++) {
        ll res = 0;
        for (ll j=1;j<i;j++) {
            f[i] += a[i] - a[j];
            res += f[i];
        }
        if (res >= m and a[i] != a[i + 1]) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}

