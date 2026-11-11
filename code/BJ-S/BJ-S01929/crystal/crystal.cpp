#include <bits/stdc++.h>
#define int long long
#define N 500005

using namespace std;

int n,m,a[N],c[N],ans=1;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        c[i]=a[i]-a[i-1];
    int l=1,r=2,res=0;
    while(r<=n)
    {
        res+=c[r]*(r-l);
        while(res>m)
            res-=a[r]-a[l],++l;
        ans=max(ans,r-l+1);
        ++r;
    }
    cout<<ans<<'\n';
    return 0;
}
