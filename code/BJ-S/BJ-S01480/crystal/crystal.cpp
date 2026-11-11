#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int sum = 0, ans = 0;
    int l, r; l = r = 1;
    while (r <= n){
        sum += a[r];
        while (l <= r && a[r] * (r - l + 1) - sum > m){
            sum -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    cout << ans << endl;
    return 0;
}
