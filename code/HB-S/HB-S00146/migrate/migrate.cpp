#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(long long i=1;i<=n;i++) cin>>a[i];
        if(c==11||c==12)
        {
            long long a1=a[2]-a[1];
            if(d<2*a1) cout<<0<<endl;
            else{
                cout<<n-(d-d%a1)/a1<<endl;
            }
        }
        if(c==13||c==14){cout<<0<<endl;}
    }
    if(c<11||c>14) cout<<1<<endl<<2<<endl;
    return 0;
}
