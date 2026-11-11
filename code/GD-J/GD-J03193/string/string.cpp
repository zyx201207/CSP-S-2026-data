#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _for(i, x, y) for(int i = (x); i <= (y); ++i)
const int N = 2e5 + 5;
ll n, a[N], ans;
char c[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    ll l = 1, r = n;
    _for(i, 1, n) cin >> a[i] >> c[i];
    while(l <= r){
        if(c[l] == c[r]){
        	ll maxn = min(a[l], a[r]);
            a[l] -= maxn, a[r] -= maxn;
            if(a[l] <= 0) ++l;
			if(a[r] <= 0) --r;
        }
        if(c[l] != c[r]){
            ll maxn = min(a[l], a[r]);
            a[l] -= maxn, a[r] -= maxn, ans += maxn;
            if(a[l] <= 0) ++l;
            if(a[r] <= 0) --r;
        }
    }
    cout << ans;
    return 0;
}

