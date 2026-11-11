#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int a, int b){ return a < b; }
inline long long rd(){
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9'){
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9'){
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n = rd(), m = rd(), ans = 0;
    ll a[n + 5] = {};
    for (int i = 0; i < n; i++){
        a[i] = rd();
    }
    int flag = 1, cha = a[1] - a[0];
    for (int i = 1; i < n - 1; i++){
        if (a[i + 1] - a[i] != cha){
            flag = 0;
            break;
        }
    }
    if (flag){
        ans = 1;
        for (int i = 1; i < n; i++){
            ll need_m = i * (i + 1) / 2 * cha;
            if (need_m <= m){
                ans = i + 1;
            }
            else {
                cout << ans;
                return 0;
            }
        }
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++){
        if (i == 0){
            ans = 1;
            continue;
        }
        ll tmp = m, tans = 1;
        for (int j = i - 1; j >= 0; j--){
            int cha = a[i] - a[j];
            if (cha > 0){
                if (tmp >= cha){
                    tmp -= cha;
                    tans++;
                }
                else break;
            }
            else if (cha == 0) tans++;
        }
        ans = max(tans, ans);
    }
    cout << ans << '\n';
    return 0;
}
