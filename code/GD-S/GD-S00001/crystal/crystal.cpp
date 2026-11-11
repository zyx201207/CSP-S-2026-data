#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const int maxn=5e5+5;
int n,ans;
ll m,a[maxn];
int main()
{
    freopen("./crystal.in","r",stdin);
    freopen("./crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll tmp=m;
    sort(a+1,a+1+n);
    for(int i=1,r=1;i<=n;i++){
        while(r<=n&&tmp>=(a[r]-a[r-1])*(r-i)){
            tmp-=(a[r]-a[r-1])*(r-i);
            r++;
        }
        ans=max(ans,r-i);
        tmp+=a[r-1]-a[i];
    }
    cout<<ans;
    return 0;
}

