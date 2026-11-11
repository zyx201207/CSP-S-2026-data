#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
ll Max, Min = LONG_MAX;
ll maxn, id;
bool vis;
map<ll, int> mp;
ll a[N];
vector<pair<ll, ll> > d;
void solve(){
    memset(a, 0x3f, sizeof(a));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] > maxn) {
            maxn = mp[a[i]];
            id = i;
        }
        if (a[i] < a[i - 1]) vis = 1;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        d.push_back({a[i + 1] - a[i], i});
        Max = max(Max, a[i] - a[i - 1]);
        Min = min(Min, a[i] - a[i - 1]);
    }
    if (vis == 0 && Max == Min) {
        int l = 1, r = n;
        ll ans = 0;
        m /= Max;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            ll temp = (mid * mid + mid) / 2;
            if (temp <= m) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << ans + 1 << "\n";
        return ;
    }
    vector<ll> sum(n);
    for (int i = 1; i < d.size(); i++) {
        sum[i] = sum[i - 1] + d[i - 1].first;
    }
    for (int i = 1; i < d.size(); i++) {
        if (sum[i + 1] - sum[i] <= m) {
            a[d[i].second] += (sum[i + 1] - sum[i]);
            m -= (sum[i + 1] - sum[i]);
        }
    }
    mp.clear();
    Max = 0;
    for (int i = 1; i <= n; i++) {
        mp[a[i]]++;
        Max = max(Max, (ll)mp[a[i]]);
    }
    cout << Max << "\n";
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
