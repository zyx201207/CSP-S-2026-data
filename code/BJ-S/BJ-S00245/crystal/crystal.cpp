#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int xn = 500005;
int n, res; ll m, a[xn], s[xn];

inline ll val(int l, int r){
    return a[r] * (r - l) - s[r - 1] + s[l - 1];
}

inline int bs(int l, int r, int x){
    int md, ans = r;
    while(l <= r){
        md = l + r >> 1;
        if(val(md, x) <= m){
            ans = md; r = md - 1;
        }else l = md + 1;
    }
    return x - ans + 1;
}

int main(){
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    scanf("%d %lld", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i){
        s[i] = s[i - 1] + a[i];
        res = max(res, bs(1, i, i));//printf("%d:%d\n", i, bs(1, i, i));
    }
    printf("%d", res);
    return 0;
}
