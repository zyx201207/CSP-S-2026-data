#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 5e5 + 10;

ll n, m;
ll a[MAXN];
ll sum[MAXN];

bool judge(ll);

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%lld%lld", &n, &m);
    for(ll i = 1; i <= n; i++) scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    ll l = 1, r = n, best = -1;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(judge(mid)){
            best = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%lld", best);
    return 0;
}

bool judge(ll x){
    for(ll i = x; i <= n; i++){
        ll tmp1 = sum[i] - sum[i - x];
        ll tmp2 = a[i] * x;
        if(tmp2 - tmp1 <= m){
            return true;
        }
    }
    return false;
}