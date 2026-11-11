#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000011];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++)
        {
            int nt=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
            int ntt=upper_bound(a+1,a+n+1,a[nt-1]+d)-a-1;
            int nttt=upper_bound(a+1,a+n+1,a[nt-2]+d)-a-1;
            //cout<<nt<<" "<<ntt<<" "<<nttt<<"\n";
            ans+=ntt-nttt;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
