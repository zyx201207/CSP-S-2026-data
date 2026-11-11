#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int n;
ll a[N], p[N], d, ans;
int lp[N], t[N];
int mnp[N], mxp[N];
vector<pair<int, int> > vc;
void solve() {
    ans = 0;
    scanf("%d%lld", &n, &d);
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    vc.clear();
    a[0] = a[1] - d;
    int ps = 0;
    for(int i = 1; i <= n; ++i) {
        while(a[i] - a[ps] > d) ++ps;
        lp[i] = ps;
        mnp[i] = n;
        mxp[i] = 1;
    }
    int qs = 1;
    ps = 1;
    int last = -1;
    for(int i = 1; i <= n; ++i) {
        if(!lp[i]) continue;
        if(lp[i] == lp[i + 1]) continue;
        if(lp[i] >= i - 1) {
            last = i;
            continue;
        }
        int ta = lp[i], tb = lp[i] + 1;
        while(ps < ta && a[tb] - a[ps] > d) ++ps;

        int tc = lp[i] + 2;
        qs = ps;
        while(qs < ta && a[tc] - a[qs] > d) ++qs;
        --qs;
        if(last == -1) last = i - 1;
        if(ps > qs || ps >= ta) {
            last = i;
            continue;
        }
        ans += 1ll * (i - last) * (qs - ps + 1);
        last = i;
        vc.push_back({ps, i});
        for(int j = ps; j <= qs; ++j)
            mnp[j] = min(mnp[j], last + 1);
        for(int j = last + 1; j <= i; ++j)
            mxp[j] = max(mxp[j], qs);
    }
    printf("%lld\n", ans);
}
ll dp[5005][5005], ps[5005][5005];
void sv() {
    ll ans = 0;
    scanf("%d%lld", &n, &d);
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dp[i][j] = 1ll << 60, ps[i][j] = 0;
    for(int i = 1; i <= n; ++i)
        dp[i][i] = 0;
    for(int i = 2; i <= n; ++i)
    for(int l = 1; l + i - 1 <= n; ++l) {
        int r = l + i - 1;
        if(a[r] - a[l] <= d) {
            dp[l][r] = 1;
            ps[l][r] = 1;
            continue;
        }
        int cnt = 0;
        for(int j = l + 1; j < r; ++j) {
            ll t = dp[l][j] + dp[j][r];
            if(t == dp[l][r]) cnt += ps[l][j] * ps[j][r];
            if(t < dp[l][r]) {
                dp[l][r] = t;
                cnt = ps[l][j] * ps[j][r];
            }
        }
        if(dp[l][r] < (1ll << 60)) {
            ps[l][r] = cnt;
            if(cnt == 2) ++ans;
        }
    }
    printf("%d\n", ans);
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    scanf("%d%d", &c, &T);
    if(c <= 10) {
        while(T--) sv();
    }
    else while(T--) solve();
}
