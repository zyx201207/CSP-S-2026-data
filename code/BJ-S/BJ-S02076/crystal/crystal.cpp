#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
typedef long long ll;

int n;
ll m, a[N], s[N],
   r, g, dif, need;

bool check(ll x){
    // Combine x crystals
    need = LONG_LONG_MAX;
    for(ll i=x; i<=n; i++){
        r = s[i] - s[i-x];
        g = a[i] * x;

        dif = g - r;
        need = min(dif, need);
    }
    return need <= m;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i=1; i<=n; i++)
        s[i] = s[i-1] + a[i];

    ll L = 1, R = n, mid, ans = 1;
    while(L < R){
        mid = (L + R) / 2;
        if(check(mid))
            ans = mid,
            L = mid + 1;
        else
            R = mid - 1;
    }
    if(check(L)) cout << L;
    else cout << ans;

    return 0;
}
