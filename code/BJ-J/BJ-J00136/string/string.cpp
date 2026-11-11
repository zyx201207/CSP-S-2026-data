#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, a[N], ans;
char c[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> c[i];
    long long l = 1, li = 1, r = 1, ri = n;
    while (li < ri)
        if (a[li] - l < a[ri] - r ){
            if (c[li] != c[ri])
                ans += a[li] - l + 1;
            r += a[li] - l + 1, l = 1, li ++;
        } else if (a[li] - l > a[ri] - r){
            if (c[li] != c[ri])
                ans += a[ri] - r + 1;
            l += a[ri] - r + 1, r = 1, ri --;
        } else if (a[li] - l == a[ri] - r){
            if (c[li] != c[ri])
                ans += a[li] - l + 1;
            li ++, ri --, l = 1, r = 1;
        }
    cout << ans;
    return 0;
}
