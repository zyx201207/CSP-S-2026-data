#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];
signed main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int n , L = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    for (int i = 1; i <= n; i++) L += a[i];
    int l = 1 , r = n;
    int ans = 0;
    while(l <= r){
        if (a[l] < a[r]){
            if (c[l] != c[r]) ans += a[l];
            a[r] -= a[l];
            l++;
        }
        else if (a[l] == a[r]){
            if (c[l] != c[r]) ans += a[l] * 2;
            l++;
            r--;
        }
        else{
            if (c[l] != c[r]) ans += a[r];
            a[l] -= a[r];
            r--;
        }
    }
    cout << ans;
    return 0;
}
