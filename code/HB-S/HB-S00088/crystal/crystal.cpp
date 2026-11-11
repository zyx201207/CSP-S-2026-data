#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5e5 + 5;
int n , ans = 1;
ll m;
ll a[N] , sf[N];

int main () {
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1 , a + 1 + n);
    for (int i = 1; i <= n; i ++)
        sf[i] = sf[i - 1] + a[i];
    for (int i = 2; i <= n; i ++)
        if (a[i] * (i - 1) - sf[i - 1] <= m)
            ans = max(ans , i);
    cout << ans;
    return 0;
}
