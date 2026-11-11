#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(a) \
(freopen(#a".in", "r", stdin),\
freopen(#a".out", "w", stdout))
const int N = 2e5+5;
int n, a[N], l, r;
char c[N];
ll len, pre, suf, ans;

int main(){
    ios::sync_with_stdio(false);
    file(string);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i] >> c[i];
        len += a[i];
    }

    l = 1;
    r = n;
    pre = a[1];
    suf = len + 1 - a[n];
    while(l < r){
        if(c[l] != c[r]){
            ll _l = pre-a[l]+1, l_ = pre;
            ll _r = len-suf-a[r]+2, r_ = len+1-suf;
            ans += min(l_, r_) - max(_l, _r) + 1;
        }

        if(pre < len+1-suf) pre += a[++l];
        else if(pre == len+1-suf) pre += a[++l], suf -= a[--r];
        else suf -= a[--r];
    }

    cout << ans;

    return 0;
}
