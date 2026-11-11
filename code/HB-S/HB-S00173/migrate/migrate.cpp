#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,m,a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll c;
    cin>>c>>t;
    bool flag=0;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=2;i<=n;i++)
        {
            if(a[i]-a[i-1]!=a[2]-a[1])
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            ll q=a[2]-a[1];
            //cout<<n<<' '<<m<<' '<<q<<'\n';
            int res=m/q;
            if(m<=q||res==n)
            {
                cout<<0<<'\n';
                continue;
            }
            cout<<n-2*res+1<<'\n';
        }
    }
    return 0;
}
