#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("./crystal.in","r",stdin);
    freopen("./crystal.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    ll n,m,ans=0;
    vector<ll>arr;
    cin >> n >> m;
    for (ll i = 0;i < n;i++) {
        ll tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    ll target = arr[int(n/2)];
    for (ll i = 0;i <= n/2;i++) {
        if (arr[i] == target) {
            ans++;
            continue;
        }
        if (m > 0) {
            m-=target-arr[i];
            ans++;
        }
    }
    for (ll i = n/2+1;i < n;i++) {
        if (arr[i] == target) {
            ans++;
        }
    }
    if (ans!=1)
        cout << ans;
    else
        cout << 0;
    return 0;
}