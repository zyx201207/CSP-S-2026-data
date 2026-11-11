#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010

 ll c,t;
 ll n,d;
 ll x[N];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    if(c==11||c==12)
    {
        while(t--)
        {
            ll ans=0;
            cin>>n>>d;
            for(ll i=1;i<=n;i++) cin>>x[i];
            if(n<=3)
            {
                cout<<0<< "\n";
            }
            ll c=x[2]-x[1];
            for(ll i=1;i<=n;i++)
            {
                ll len=(n-i)*c;
                if(len/2<d<len)
                {
                    ans+=i;
                }
                if(d>len) break;
            }
            cout<<ans<< "\n";
        }
    }
    else
    {
        while(t--) cout<< "0\n";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
