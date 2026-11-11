#include<bits/stdc++.h>
typedef long long ll;


const int MAXN = 5e5 + 10;
bool den;
ll c, t, n, d, ans;
ll a[MAXN];

ll low(ll x){
    ll l = 0, r = n + 1, t = 24;
    while(t-- && l <= r){
        ll mid = ((l + r) >> 1);
        if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

ll high(ll x){
    ll l = 0, r = n + 1, t = 24;
    while(t-- && l <= r){
        ll mid = ((l + r) >> 1);
        if(a[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}


bool check(ll now, ll idx){
    ll cnt = 0;
    for(int i = 1;i <= d;i++) cnt += ((a[high(a[idx] - i)] == a[idx] - i) && (a[idx] - i - a[now]) <= d);
    return cnt == 2;
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld %lld", &c, &t);
    while(t--){
        ans = 0, den = true;;
        scanf("%lld %lld", &n, &d);
        for(int i = 1;i <= n;i++) scanf("%lld", a + i);
        for(int i = 2;i < n;i++){
            if(a[i + 1] - a[i] != a[i] - a[i - 1]) den = false;
        }
        if(den){
            ll d1 = high(a[1] + d);
            ll d2 = low(d1 + d);
            ans = (n - d2 + 1) * (d2 - d1);
            printf("%lld\n", ans);
            continue;
        }

        for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(a[j] - a[i] <= d) continue;
            if(check(i, j)) ans++;
        }}
        printf("%lld\n", ans);
    }
    return 0;
}