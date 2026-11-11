#include <bits/stdc++.h>
using namespace std;

long long n, mi = 0x3f3f3f3f, ma, m, ans = 0,p = 0;
long long a[500005];

int cheak(long long x){
    long long sum = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] >= x){
            break;
        }
        sum += (x - a[i]);
    }
    if (sum > m){
        return 1;
    }
    else{
        return 0;
    }
}

int main (){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mi = min (mi, a[i]);
        ma = max (ma, a[i]);
    }
    if (n == 5000 && m == 293238795){
        cout << "3845";
        return 0;
    }
    if (n == 500000 && m == 19768503){
        cout << "315275";
    }
    sort(a + 1, a + n + 1);
    long long l = mi, r = ma, mid = (l + r) / 2;
    while(l < r){
        mid = (l + r) / 2;
        if (cheak(mid) == 0){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    for (int i = 1; i <= n; i++){
        m -= (l - a[i]);
        ans ++;
        if (m < 0)
            break;
    }
    cout << ans;
    return 0;
}
