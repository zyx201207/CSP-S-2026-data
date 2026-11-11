#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
constexpr int N = 5e5+10;
int n;
ll m, a[N];

ll t1[N], t2[N];
void add1(int x, ll val){
    for(int i = x; i <= n; i += (i&-i))
        t1[i] += val;
}
void add2(int x, ll val){
    for(int i = x; i <= n; i += (i&-i))
        t2[i] += val*(x-1);
}
ll sum1(int x){
    ll res = 0;
    for(int i = x; i; i -= (i&-i))
        res += t1[i];
    return res;
}
ll sum2(int x){
    ll res = 0;
    for(int i = x; i; i -= (i&-i))
        res += t2[i];
    return res;
}
void update(int l, int r, ll val){
    add1(l, val);add2(l, val);
    if(r+1 <= n) add1(r+1, -val), add2(r+1, -val);
}
ll query(int r){
    ll sumr = r*sum1(r)-sum2(r);
    return sumr;
}
ll calc(int x){
    if(x == 0) return 0;
    ll sumr = query(x);
    int l = 0, r = x;
    while(l < r){
        int mid = (l+r)>>1;
        ll tmp = sumr-query(mid);
        if(tmp <= m) r = mid;
        else l = mid+1;
    }
    return x-r;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%lld", a+i);
    sort(a+1, a+n+1);
    ll ans = 1;
    for(int i = 1; i <= n; ++i){
        update(1, i-1, a[i]-a[i-1]);
        //cout << query(1) << '\n';
        //cout << t1[n] << '\n';
        ans = max(ans, calc(i-1)+1);
    }
    printf("%lld", ans);
    return 0;
}
