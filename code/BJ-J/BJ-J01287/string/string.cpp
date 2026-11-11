#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 10;
int n, a[maxn];
char c[maxn];
int count() {
    int res = 0;
    int l = 1, r = n;
    while(l <= r) {
        if(a[l] >= a[r]) {
            if(c[l] != c[r]) res += a[r];
            a[l] -= a[r];
            r--;
        } else {
            if(c[l] != c[r]) res += a[l];
            a[r] -= a[l];
            l++;
        }
    }
    return res;
}
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    cout << count() << "\n";
    return 0;
}