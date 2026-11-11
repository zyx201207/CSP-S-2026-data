#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=2e5+6;
int n;
ll a[N],s[N],ans;
char c[N*2];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int l=1,r=n;
    while (l<r) {
        ll t=min(a[l],a[r]);
        if (c[l]!=c[r]) ans+=t;
        if (a[l]==t) {
            l++;
            a[r]-=t;
        } else {
            r--;
            a[l]-=t;
        }
    }
    cout<<ans;
    return 0;
}
