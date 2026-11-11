#include <bits/stdc++.h>
using namespace std;
int n, a[500005];
unsigned long long m;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d %llu", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }
    sort(a, a + n);
    int l = 0, r = 0;   // [l, r]
    int ans = 1;
    unsigned long long cost = 0ull;
    while(l <= n && r <= n) {
        r++;
        cost += (a[r]-a[r-1]) * (r-l);
        while(l <= r && cost > m) {
            l++;
            cost -= a[r] - a[l];
        }
        ans = max(ans, r - l +1);
    }
    cout << ans;
    return 0;
}
