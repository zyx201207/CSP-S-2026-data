#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5e5 + 6;
ll ans;
ll n,m;
ll a[MAXN],sa[MAXN];
bool check(int x,int y) {
    return (sa[y] - sa[x - 1]) <= (n + (y - x + 1) * (a[n] - a[y]));
}
ll find(ll ed) {
    ll ans = 1;
    ll l = 1,r = ed;
    while (l <= r) {
        ll mid = (l + r + 1) / 2;
        if (check(mid,ed)) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    return ans;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 0;i < n;i++) cin >> a[i];
    sort (a + 1,a + n + 1);
    for (int i = 0;i < n;i++) sa[i] = sa[i - 1] + a[n] - a[i];
    for (int i = 0;i < n;i++) ans = max(ans,i - find(i) + 1);
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}