#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 2e5 + 10;

ll n, m;
ll a[MAXN];

bool judge(ll);

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    scanf("%lld%lld", &n, &m);
    for(ll i = 1; i <= n; i++) scanf("%lld", a + i);

    ll ans = 0;
    for(ll i = 31; i >= 0; i--){
        ll tmp = (1 << i), tans = ans | tmp;
        if(judge(tans)) ans = tans;
    }

    printf("%lld", ans);
    return 0;
}

bool judge(ll x){
    ll cnt = 0;
    for(ll i = 1; i <= n; i++) if((a[i] & x) == x)
        cnt++;
    return (cnt >= m);
}