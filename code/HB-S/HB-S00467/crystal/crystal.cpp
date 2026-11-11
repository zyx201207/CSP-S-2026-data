#include<bits/stdc++.h>
using namespace std;

#define my long long
const my N = 5e5 + 5;

my n, m, a[N], ans;

bool check(my mid){
    my cnt = 0;
    for(my i = 1; i <= n; i++){
        if(mid > a[i]) cnt += (mid - a[i]);
    }
    return cnt <= m;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(my i = 1; i <= n; i++){
        cin >> a[i];
    }
    my l = -1e12, r = 1e12, x = 1e18;
    while(l <= r){
        my mid = (l + r) >> 1;
        if(check(mid) == true){
            x = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    for(my i = 1; i <= n; i++){
        if(x >= a[i]) ans++;
    }
    cout << ans;
    return 0;
}

