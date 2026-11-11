#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5+5;

ll a[N], d[N];
int n, m;

bool check(int l){
    int end = l - 1;
    ll cost = 0;
    for (int i = 0; i < end; i++){
        cost += a[end] - a[i];
    }
    if (cost <= m) return true;
    for ( ; end < n-1; end++){
        cost -= a[end] - a[end - l + 1];
        cost += (a[end + 1] - a[end])*(l-1);
        if (cost <= m) return true;
    }
    return false;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i < n; i++) d[i] = a[i] - a[i-1];
    int l = 1, r = n;
    int ans = 0;
    while (l <= r){
        int mid = (l + r)>>1;
        if (check(mid)){
            ans = max(ans, mid);
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}