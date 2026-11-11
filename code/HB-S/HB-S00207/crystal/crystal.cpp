#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
ll n, m, a[maxn], ans = -1e9;
ll sum[maxn];
bool check(ll x){
    int i = x;bool f = 0;
    for(i = x;i <= n;i++){
        ll sm = sum[i] - sum[i - x];
        //if(sm < 0) continue;
        ll w = a[i] * x - sm;
        //cout << i << ' ' << ' ' << "w = " << w << '\n';
        if(w >= 0 && w <= m) f = 1;
    }
    if(f) return 1;
    else return 0;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, j;
    cin >> n >> m;//19768503
    for(i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
    /*
    for(i = 1;i <= n;i++){
        ll t = m, cnt = 0;
        for(j = i;j;j--){
            if(t >= a[i] - a[j]){
                t -= a[i] - a[j];
                cnt++;
            }else break;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    */

    ll l = 1, r = n;ans = 1;
    while(l < r){
        ll mid = l + r >> 1;
        //cout << "mid = " << mid << '\n';
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid;
    }
    cout << ans;
    return 0;
}
