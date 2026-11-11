#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define ll long long
const int MAXN = 5e5+10;

ll m;
int ans = 0, n;
ll a[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin>>n>>m;
    if (n==1) {
        cout<<1;
        return 0;
    }

    bool isA = true; ll isAn; //A
    ll mina = 1e12+10, diff = 0; //B
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (i==1) isAn = a[i];
        else if (a[i] != isAn) isA = false;

        mina = min(mina, a[i]);
    }

    if (isA) {
        cout<<m; //A: m == ans
        return 0;
    }

    // defaultB
    for (int i=1;i<=n;++i) a[i] = a[i] - mina;
    diff = abs(a[1] - a[2]);
    
    ll tmpm = 0;
    for (int i=2;i<=n;++i) {
        if (tmpm + (i-1)*diff <= m) ans = i, tmpm+=(i-1)*diff;
        else break;
    }

    cout<<ans;

    return 0;
}
