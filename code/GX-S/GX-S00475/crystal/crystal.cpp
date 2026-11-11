#include <bits/stdc++.h>
#define ll long long
#define getchar getchar_unlocked
using namespace std;
const int N = 5e5 + 10;
const ll inf = 2e18 + 10;
int n;
ll m;
ll a[N], sum[N];
inline ll read(){
    char c = getchar();
    int flag = 1;
    ll ans = 0;
    while(! (c >= '0' && c <='9')){
        if(c == '-') flag = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ans = (ans << 3) + (ans << 1) + c - '0';
        c = getchar();
    }
    return ans * flag;
}
inline ll calc(int x){
    ll res = inf;
    for(int i = x; i <= n; i ++){
        res = min(res, a[i] * x - sum[i] + sum[i - x]);
    }
    return res;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; i ++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(calc(mid) <= m) l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}
