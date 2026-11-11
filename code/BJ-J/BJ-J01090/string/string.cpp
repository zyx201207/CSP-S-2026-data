#include <bits/stdc++.h>
using namespace std;
const int LPLCBYBS = 2e5+10;
long long a[LPLCBYBS] = {};char c[LPLCBYBS] = {};
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i]>>c[i];
    }
    long long L = 1,R = n,ans = 0;
    while(L < R) {
        long long op = min(a[L],a[R]);
        a[L]-=op;a[R]-=op;
        if(c[L] != c[R]) ans += op;
        if(!a[L]) L++;
        if(!a[R]) R--;
    }
    cout<<ans;
    return 0;
}
//Trick||Treat!
//       O
//      >/
//       S
//       11
//
//
//
