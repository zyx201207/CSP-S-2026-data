#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,tc,n,d,x[1000005],f[1000005],g[1000005],h[1000005];
void solve()
{
    cin>>n>>d;
    for(int i = 1; i <= n; i++) cin>>x[i];
    int ans=0,np=0;
    for(int nl = 1; nl <= n; nl++)
    {
        int mindl=nl,nans=0;
        f[nl]=0;
        g[nl]=1;
        h[nl-1]=0;
        h[nl]=1;
        for(int nr = nl+1; nr <= n; nr++)
        {
            while(x[nr]-x[mindl]>d) mindl++;
            f[nr]=f[mindl]+1;
            g[nr]=0;
            if(f[nr]!=f[nr-1])
            {
                g[nr]=h[nr-1]-h[mindl-1];
                np=nr;
            }
            else
            {
                g[nr]=h[np-1]-h[mindl-1];
            }
            g[nr]=(g[nr]%1000000009+1000000009)%1000000009;
            if(g[nr]==2) nans++;
            // cout<<f[nr]<<' '<<np<<' ';
            h[nr]=(h[nr-1]+g[nr])%1000000009;
        }
        // cout<<'\n';
        ans+=nans;
    }
    cout<<ans<<'\n';
    return;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>tc;
    while(tc--)
    {
        solve();
    }
}