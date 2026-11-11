#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=5e5+6;
int n,ans;
ll m,a[N],s[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for (int l=1,r=1;l<=n;l++) {
        while (r<=n&&(r-l)*a[r]-s[r-1]+s[l-1]<=m) r++;
        ans=max(ans,r-l);
    }
    cout<<ans;
    return 0;
}
