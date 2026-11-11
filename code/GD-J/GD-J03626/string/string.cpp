#include<bits/stdc++.h>


const int MAXN = 2e5 + 10;
long long n, ans, l, r, ll, rl, lc, rc;
long long a[MAXN];
char c[MAXN];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    std::cin >> n;
    for(long long i = 1;i <= n;i++) std::cin >> a[i] >> c[i];
    
    l = 1, r = n;
    while(l <= r){
        if(ll){
            if(ll >= a[r]){
                if(lc != c[r]) ans += a[r];
                ll -= a[r], r--;
                continue;
            }
            if(lc != c[r]) ans += ll;
            a[r] -= ll, ll = 0;
        }
        if(rl){
            if(rl >= a[l]){
                if(rc != c[l]) ans += a[l];
                rl -= a[l], l++;
                continue;
            }
            if(rc != c[l]) ans += rl;
            a[l] -= rl, rl = 0;
        }

        if(c[l] != c[r]) ans += std::min(a[l], a[r]);
        if(a[l] < a[r]) rl = (a[r] - a[l]), rc = c[r];
        else if(a[l] > a[r]) ll = (a[l] - a[r]), lc = c[l];
        l++, r--;
    }
    std::cout << ans;
    
    return 0;
}