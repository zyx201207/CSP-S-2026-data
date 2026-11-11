#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n , m , ans = 0;
int a[N];
bool check(int x) {
    int sum = 0 , ans = -1;
    int u = a[x];
    for(int i = 1 ; i <= n ; i++) {
        if(a[i] == a[x]) ans++;
    }
    for(int i = 1 ; i <= n ; i++){
        if(a[i] < a[x] && ans < x) {
            sum += a[x] - a[i];
            ans++;
        }
    }
    return sum <= m;
}
signed main () {
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
    int l = 0 , r = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}