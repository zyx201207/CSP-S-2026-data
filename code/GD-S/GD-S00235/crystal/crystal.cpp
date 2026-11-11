#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 5e5 + 5;
int n; ll m, a[MAXN], s[MAXN];

signed main(){
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    int ans = 1;
    for(int i = 2; i <= n; ++i){
        int l = 1, r = i, res = i;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - res + 1);
    }
    cout << ans << '\n';

    return 0;
}