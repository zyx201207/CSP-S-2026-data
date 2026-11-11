#include <bits/stdc++.h>
using namespace std;
long long n, m, a[600000], ans = 1;
bool ok = true;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 3;i <= n;i++){
        if(a[i - 1] - a[i - 2] != a[i] - a[i - 1]){
            ok = false;
        }
    }
    if(ok == true){
        long long rp = m;
        for(int i = n - 1;i > 0;i--){
            if(rp >= a[n] - a[i]){
                rp -= a[n];
                rp += a[i];
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    for(int i = 2;i <= n;i++){
        long long r = 1, p = m;
        for(int j = i - 1;j > 0;j--){
            if(p >= a[i] - a[j]){
                p -= a[i];
                p += a[j];
                r++;
            }
        }
        ans = max(ans, r);
    }
    cout << ans;
    return 0;
}
