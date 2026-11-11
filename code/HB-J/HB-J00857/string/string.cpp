#include<bits/stdc++.h>
using namespace std;
long long n, ans;
int a[211111];
char c[211111];
int main (){
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> c[i];
    int l = 1, r = n, len;
    while (l < r){
        len = min (a[l], a[r]);
        if (c[l]!=c[r]) ans += len;
        a[l] -= len,
        a[r] -= len;
        if (a[l]==0) l++;
        if (a[r]==0) r--;
    }
    cout << ans << "\n";

    return 0;
}
