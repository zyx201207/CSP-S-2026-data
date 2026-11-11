#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e6+5;
long long C,T,n,m,a[maxn],d[maxn],t[maxn],ans,k[maxn],p;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        t[n]=n;
        for(int i=n-1;i>=1;i--)
        {
            t[i]=t[i+1];
            while(a[t[i]]-a[i]>m)t[i]--;
        }
        if(C==13||C==14)
        {
            for(int i=1;i<=n;i++)
            {
                if(t[i]==i||t[i]==i+1)continue;
                ans+=t[t[i]-1]-t[t[i]-2];
            }
            cout<<ans<<"\n";
            continue;
        }
        for(long long r=1;r<=n;r++)
        {
            p=0;
            d[r]=0;
            for(int l=r-1;l>=1;l--)
            {
                if(t[l]==l)
                {
                    p=l;
                    break;
                }
                d[l]=d[min(t[l],r)]+1;
            }
            k[r]=1;
            for(int l=r-1;l>p;l--)
            {
                k[l]=k[min(t[l],r)];
                if(min(t[l],r)-1>p&&d[min(t[l],r)-1]==d[min(t[l],r)])k[l]+=k[min(t[l],r)-1];
                if(min(t[l],r)-2>p&&d[min(t[l],r)-2]==d[min(t[l],r)])k[l]+=k[min(t[l],r)-2];
                if(k[l]==2)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*

*/