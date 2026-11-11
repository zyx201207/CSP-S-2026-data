#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
        }
        long long tt=a[2]-a[1];
        if(d<1LL*2*tt||d>=1LL*(n-1)*tt)
        {
            cout<<0<<'\n';
        }
        else
        {
            long long m=d/tt;
            cout<<n-1LL*2*m+1<<'\n';
        }
    }
    return 0;
}
