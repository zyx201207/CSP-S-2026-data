#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 500005

int n, m; int a[MAXN];

signed main(){
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m; for (int i(1); i<=n; ++i) cin >> a[i]; sort(a+1, a+n+1); int ans(0);
    for (int i(1), p(1), s(0); i<=n; ++i){
        for (; p<=i && s>m; ++p) s -= a[i]-a[p]; ans = max(ans, i-p+1);
        if (i < n) s += (a[i+1]-a[i])*(i-p+1);
    }
    cout << ans;

    return 0;
}