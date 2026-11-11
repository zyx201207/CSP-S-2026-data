#include<bits/stdc++.h>

using namespace std;
int n;
bool f = true, f2 = true;
long long m, a[500010], ans, diff[500010], sum[500010];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != i) f = false;
    }
    sort(a + 1, a + n + 1);
    if(m == 0){
        long long cnt = 1;
        ans = 1;
        for(int i = 2; i <= n; i++){
            if(a[i] == a[i - 1]){
                cnt++;
            }else{
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        cout << max(ans, cnt) << '\n';
        return 0;
    }
    if(f){
        cout << min(ceil(sqrt(m * 2)), 1.0 * n) << '\n';
        return 0;
    }
    for(int i = 3; i <= n; i++){
        if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
            f2 = false;
            break;
        }
    }
    if(f2){
        cout << min(ceil(sqrt(2.0 * m / ((a[n] - a[n - 1]) * 1.0))), 1.0 * n);
        return 0;
    }
    for(int i = n - 1; i >= 1; i--) diff[i] = a[i + 1] - a[i];
    for(int i = n; i >= 1; i--) sum[i] = diff[i] + sum[i + 1];
    for(int i = n; i >= 1; i--){
        int now = 0;
        for(int j = i; j >= 1; j--){
            now += sum[j] - sum[i];
            if(now <= m){
                ans = max(ans, (i - j + 1) * 1ll);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
