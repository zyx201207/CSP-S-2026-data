#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,m,a[2000005],b[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ll s=0,t=0;
        cin>>n>>m;
        for(ll i=1;i<=n;i++)
            scanf("%lld",&a[i]),b[i]=a[i]-a[i-1];
        for(ll i=1;i<=n;i++)
        {
            s+=b[i];
            if(s>m)
            {
                t++;
                s=b[i];
            }
        }
        if(t>2) cout<<"0"<<endl;
        else cout<<"1"<<endl;
    }
    return 0;
}
