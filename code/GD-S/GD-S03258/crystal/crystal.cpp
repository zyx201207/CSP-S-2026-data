#include<bits/stdc++.h>
typedef long long ll;


const int MAXN = 5e5 + 10;
ll n, m;
ll a[MAXN];
ll sum[MAXN];
bool check(ll x){
    for(ll i = x;i <= n;i++){
        if((a[i] * x - (sum[i] - sum[i - x])) <= m) return true;
    }
    return false;
}


int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(ll i = 1;i <= n;i++) scanf("%lld", a + i);
    
    std::sort(a + 1, a + n + 1);
    for(ll i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];

    ll l = 0, r = n;
    for(int i = 0;i < 100 && l < r;i++){
        ll mid = ((l + r) >> 1);
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%lld\n", l);

    return 0;
}
