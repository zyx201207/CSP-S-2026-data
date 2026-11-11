#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[1000005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int i,j,k,dd;
    cin>>c>>t;
    while (t--)
    {
        bool flag=true;
        cin>>n>>d;
        for (i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i==2)
                dd=a[i]-a[i-1];
            else if(i>=2)
            {
                if(a[i]-a[i-1]!=dd)
                    flag=false;
            }
        }
        if(flag)
        {
            for(i=3;i<=n;i+=dd)
                if ((i-1)*dd<=d&&d<i*dd)
                {
                    cout<<n-i<<endl;
                    break;
                }
        }
    }
}
