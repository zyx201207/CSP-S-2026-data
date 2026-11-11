#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005];
    char c[200005];
    long long ans=0;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int l=1,r=n;
    while(l<r)
    {
        int need=min(a[l],a[r]);
        a[l]-=need;
        a[r]-=need;
        if(c[l]!=c[r]) ans+=need;
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    cout << ans;
    return 0;
}
