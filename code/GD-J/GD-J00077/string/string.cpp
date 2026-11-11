#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;
struct Info{
    ll siz;
    char c;
}a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].siz >> a[i].c;
    ll ans = 0;
    int l = 0, r = n + 1;
    ll lsiz = 0, rsiz = 0;
    while(l < r){
        l++;
        if(a[l].c != a[r].c)
            ans += min(rsiz - lsiz, a[l].siz);
        lsiz += a[l].siz;
        while(l < r && rsiz < lsiz){
            r--;
            if (a[l].c != a[r].c)
                ans += max(0LL, min(lsiz - rsiz, a[r].siz));
            rsiz += a[r].siz;
        }
    }
    cout << ans;
    return 0;
}
