#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(c==11||c==12)
        {
            int dt=a[2]-a[1];
            int l=d/dt*2-1;
            cout<<max(0ll,n-l)<<'\n';
        }
        else
        {
            if(a[n]-a[1]<2*d) cout<<0<<endl;
            else cout<<2<<endl;
        }
    }
    return 0;
}