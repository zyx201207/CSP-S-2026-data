#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],nl=1,nop,ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++)
    {
        nop+=(i-nl)*(a[i]-a[i-1]);
        // cout<<nop<<'\n';
        while(nop>m)
        {
            nop-=(a[i]-a[nl]);
            nl++;
        }
        ans=max(ans,i-nl+1);
        // cout<<nl<<' '<<ans<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}