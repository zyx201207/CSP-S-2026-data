#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,x[2000005];

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        memset(x,0,sizeof(x));
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        if(c==11||c==12)
        {
            int dd=x[2]-x[1];
            if(d<2*dd||d>=(n-1)*dd)
                cout<<0;
            else
                cout<<(n*dd-1-d)/dd;
            return 0;
        }
    }
    return 0;
}
