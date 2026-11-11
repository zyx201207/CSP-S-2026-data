#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
int n;
ll m , a[N] , s[N];
bool Check(int x) {
    ll minn = 9e18;
    for(int l = 1;l <= n;l++) {
        int r = l + x - 1;
        if(r > n) break;
        minn = min(minn , (x - 1) * a[r] - (s[r - 1] - s[l - 1]));
    }
    return (minn <= m);
}
int main() {
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1 , a + n + 1);
    for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
    int l = 1 , r = n;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        // cout << l << " " << r << ": " << mid << endl;
        if(Check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}