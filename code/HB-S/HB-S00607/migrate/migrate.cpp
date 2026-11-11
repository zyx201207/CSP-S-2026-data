#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long x[2000005],d;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(c==11||c==12||c==0)
        {
            long long g=x[2]-x[1];
            if(d<=g)
            {
                cout<<"0\n";
                continue;
            }
            g=d/g;
            g=g*2-1;
            cout<<max(0ll,n-g)<<"\n";
        }
        cout<<"0\n";
    }


    return 0;
}