#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans = 0011111111111111111111111111111111111,maxn = -1,c[200005],d[32],cnt[32],num;
bool b[200005][32];
void fl(ll &q,ll &j){
    ll p = q,i = 0;
    while (p){
        b[j][i] = p % 2,p /= 2;
        if (b[i][j]) d[i] ++;
        i++;
    }
    c[j] = i;
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (ll i = 0;i < n;i++) cin >> a[i];
    for (ll i = 0;i < n;i++) maxn = max(maxn,a[i]);
    if (m == 1) cout << maxn;
    else if (m == 2){
        for (ll i = 0;i < n;i++) for (ll j = i + 1;j < n;j++) num = max(num,a[i] & a[j]);
        cout << num;
    }
    else if (m == n){
        for (ll i = 0;i < n;i++) ans = ans & a[i];
        cout << ans;
    }
    else{
        bool _ = 1;
        for (ll i = 0;i < n;i++) fl(a[i],i);
        for (ll i = 31;i >= 0;i--){
            if (d[i] < m) cnt[i] = 0;
            else if (d[i] == m) {
                for (ll j = 0;j < n;j++) if (b[j][i]) ans = ans & a[j];
                _ = 0;
                break;
            }
        }
        if (_){
            for (ll i = 31;i >= 0;i--) for (int j = 0;j < n;j++) if (b[j][i]) ans = ans & a[j];
        }
        cout << ans;
    }
    return 0;
}

