#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 1000;
int a[N];
char s[N];
int sum[N];
int n;
int num = 0;
int ans = 0;
signed main () {
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] >> s[i];
        sum[i] = sum[i - 1] + a[i];
        num += a[i];
    }
    int i = 1;
    int r = n;
    while(i <= r) {
        if(s[i] != s[r]) {
            if(a[i] > a[r]) {
                ans += a[r];
                a[i] -= a[r];
                r--;
            }
            else {
                ans += a[i];
                a[r] -= a[i];
                i++;
            }
        }
        else {
            if(a[i] > a[r]) {
                a[i] -= a[r];
                r--;
            }
            else {
                a[r] -= a[i];
                i++;
            }
        }
    }
    cout << ans;
    return 0;
}
