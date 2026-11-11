#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,sum,a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    }
    for(int i=1;i<=t;i++)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]-a[i-1]>sum)
            {
                sum=a[i]-a[i-1];
            }
        }
        if(sum<d)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
        }
    }
}
