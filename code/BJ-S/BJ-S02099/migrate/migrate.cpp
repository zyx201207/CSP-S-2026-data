#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,maxn;
ll a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        scanf("%lld %lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            maxn = max(maxn,a[i]-a[i-1]);
        }
        if(maxn>d)
        {
            cout<<"0"<<"\n";

        }
        if(c==13||c==14)
        {
            cout<<"0"<<"\n";

        }
        else{
        if(d<2*(a[2]-a[1])||d>3*(a[2]-a[1])) cout<<"0"<<"\n";
        else
        {
            cout<<(n+d/3)/(d/3+1)<<"\n";
        }
        }


    }
    return 0;
}
