#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5 + 10, INF = LLONG_MAX / 2;
ll n, m, a[N], sum[N], l , r, ans;
bool check(int mid){
    ll t, rec = INF;
    for(int i = 1; i <= n - mid + 1; i ++){
        t = mid * a[i + mid - 1] - sum[i + mid - 1] + sum[i - 1];
        rec = min(rec, t);
    }
    if(rec <= m){
        return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i ++){
        sum[i] = sum[i - 1] + a[i];
    }
    ll l = 0, r = m;
    while(l <= r){
        int mid = l + ((r - l) >> 1);
        if(check(mid)){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << l - 1 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
