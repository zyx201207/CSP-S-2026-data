#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
struct Node{
    int val;
    char c;
} a[N], b[N];
ll n, tot = 0;
ll ans = 0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].val >> a[i].c;
        tot += a[i].val;
    }
    ll ltot = n, rlen = 0, rtot = 0;
    while(rlen < tot / 2){
        rlen += a[ltot].val;
        b[++rtot] = a[ltot];
        ltot--;
    }
    a[++ltot].val = rlen - tot / 2; a[ltot].c = b[rtot].c;
    b[rtot].val -= rlen - tot / 2;
    a[ltot].val -= (tot & 1);
    int i = 1, j = 1;
    while(j <= rtot && i <= ltot){
        if(a[i].c != b[j].c) ans += min(a[i].val, b[j].val);
        a[i].val -= min(a[i].val, b[j].val);
        b[j].val -= min(a[i].val, b[j].val);
        if(!a[i].val) i++;
        if(!b[j].val) j++;
    }
    cout << ans << '\n';
    return 0;
}