#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 200005;
struct S{
    int len;
    char ch;
}a[maxn];
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].len >> a[i].ch;
    int l = 1, r = n, ans = 0;
    while(l < r){
        if(a[l].len < a[r].len){
            a[r].len -= a[l].len;
            if(a[l].ch != a[r].ch) ans += a[l].len;
            l++;
        }else{
            a[l].len -= a[r].len;
            if(a[l].ch != a[r].ch) ans += a[r].len;
            r--;
        }
    }
    cout << ans;
    return 0;
}