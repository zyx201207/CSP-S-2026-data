#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort (a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        a[i] = a[i+1] - a[i];
    }
    //int l = 1, r = 0, sum = 0, maxl = -1;
    //while (r < n) {
    //    sum += a[++r];
    //    while (sum > m) {
    //        sum -= a[l++];
    //    }
    //    maxl = max(maxl, r-l+1);
    //}
    int maxl = -1;
    for (int i = 1; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum += j*a[i-j];
            maxl = max(maxl, j+1);
            if (sum > m) break;
        }
    }
    cout << maxl;
    return 0;
}
