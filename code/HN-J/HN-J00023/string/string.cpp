#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 3e5 + 1;

ll n;
int a[N];
char c[N];
ll ans;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n;
    ll cntl = 0, cntr = 0;
    while(l < r){
        if(a[l] - cntl < a[r] - cntr){
            if(c[l] != c[r]) ans += a[l] - cntl;
            cntr += a[l] - cntl;
            l++;
            cntl = 0;
        } else if(a[l] - cntl > a[r] - cntr){
            if(c[l] != c[r]) ans += a[r] - cntr;
            cntl += a[r] - cntr;
            r--;
            cntr = 0;
        }else if(l != r){
            if(c[l] != c[r]) ans += a[r] - cntr;
            l++, r--;
            cntl = cntr = 0;
        }
        if(a[l] - cntl == 0) l++, cntl = 0;
        if(a[r] - cntr == 0) r--, cntr = 0;
    }
    cout << ans;
    return 0;
}
