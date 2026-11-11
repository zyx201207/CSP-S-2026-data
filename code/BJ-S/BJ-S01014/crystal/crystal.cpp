#include <bits/stdc++.h>
using namespace std;
const int LPL = 5e5+10;
long long a[LPL] = {},s[LPL] = {};
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans = 1,p = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        s[i] = s[i-1]+a[i];
    }
    for(int i = 1;i <= n;i++) {
        if((i-1-p)*a[i]-s[i-1]+s[p] <= m) ans = i-p;
        else {
            p++;
            if((i-1-p)*a[i]-s[i-1]+s[p] <= m) ans = i-p;
        }
    }
    cout<<ans;
    return 0;
}
