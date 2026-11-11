#include <bits/stdc++.h>
using namespace std;

long long n, m;

long long a[500001];

long long l = 1, r = 1;

long long t, s, ans;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    while (r < n){
        if (l > r){
            r++;
        }
        long long len = r - l + 1;
        if (t + len * (a[r + 1] - a[r]) <= m){
            t = t + len * (a[r + 1] - a[r]);
            r++;
            ans = max(ans, len + 1);
        }else{
            t -= a[r] - a[l];
            l++;
        }
    }

    cout << ans;

    return 0;
}
