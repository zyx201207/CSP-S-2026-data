#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 50;

int n, m, a[maxn], ans;

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int S = a[1], l = 1, ans = 1;
    for(int i = 2; i <= n; i++){
        S += a[i];
        while(a[i] * (i - l + 1) - S > m) S -= a[l], l++;
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}