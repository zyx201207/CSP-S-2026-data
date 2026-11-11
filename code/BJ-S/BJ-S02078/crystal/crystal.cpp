#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 5e5 + 10;
ll a[N], s[N], b[N], n;
ull m, t = 0;

bool cmp (ll x, ll y){
    return x > y;
}

ll er_fen(int i){
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(m + t - (n - mid) * (b[1] - b[i]) >= s[mid]) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

 int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    ll temp = a[1];
    for (int i = 1;i <= n; i++){
        b[i] = a[i];
        a[i] = temp - a[i];
        s[i] = s[i - 1] + a[i];
    }
    ll maxn = 0, l, r;
    for (ll i = 1;i <= n;i++){
        ll x = er_fen(i);
        if(maxn < x - i + 1){
            maxn = x - i + 1;
            l = i, r = x;
        }
        t += (b[i] - b[i + 1]) * (n - i);
    }
    cout << maxn << endl;
    return 0;
}