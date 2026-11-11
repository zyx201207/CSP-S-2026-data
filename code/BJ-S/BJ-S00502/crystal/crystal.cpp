#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, ans;
bool f = 1;

long long a[N], m;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (n == 1){
        cout << 1 << '\n';
        return 0;
    }
    if (n == 2){
        if (m >= a[2] - a[1]) cout << 2 << '\n';
        else cout << 1 << '\n';
        return 0;
    }
    long long d = a[2] - a[1];
    for (int i = 3; i <= n; i++){
        if (a[i] - a[i - 1] != d){
            f = 0;
            break;
        }
    }
    if (f){
        int cnt = 1;
        ans = 1;
        while (m > 0 && cnt <= n){
            m -= cnt * d;
            cnt++, ans++;
        }
        if (m < 0) ans--;
        cout << ans << '\n';
        return 0;
    }
    long long mn = a[1], mx = a[n];
    long long mid = mn + mx >> 1, now = LLONG_MAX;
    int id;
    for (int i = 1; i <= n; i++){
        if (abs(mid - a[i]) < now){
            now = abs(mid - a[i]);
            id = i;
        }
    }
    for (int i = 1; i <= n; i++) if (a[i] == a[id]) ans++;
    for (int i = id - 1; i; i--){
        if (m >= a[id] - a[i]){
            m -= (a[id] - a[i]);
            ans++;
        }else break;
    }
    if (m > 0){
        int cnt = id;
        for (int i = id + 1; i <= n; i++){
            if (m >= cnt * (a[i] - a[id])){
                m -= (cnt * (a[i] - a[id]));
                cnt++, ans++, id++;
            }else break;
        }
    }
    cout << ans << '\n';
    return 0;
}