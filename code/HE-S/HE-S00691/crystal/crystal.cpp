#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n, ans = 1;
ull m;
vector<ll> a, d;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n);
    d.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i) {
        d[i] = a[i] - a[i-1];
    }

    int l = 0, r = 0;
    ull cost = 0;
    while (l <= r && r < n) {
        if (cost <= m) {
            r++;
            ans = max(ans, r-l);
            cost += d[r]*(r-l);
        } else {
            cost -= a[r]-a[l++];
        }
    }

    cout << ans;
    return 0;
}
