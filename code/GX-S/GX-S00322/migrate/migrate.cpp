#include <bits/stdc++.h>
using namespace std;
long long n,d,i,j,c,t,x[2000005],y;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for (i=1;i<=t;i++)
    {
        cin>>n>>d;
        for (j=1;j<=n;j++)
        {
            cin>>x[j];
        }
        int t=1;
        for (j=1;j<n-1;j++)
        {
            if (x[j+1]-x[j]!=x[j+2]-x[j+1])
            {
                t=0;
            }
        }
        y=x[2]-x[1];
        if (t)
        {
            if (d>2*y)
            {
                cout<<n-2;
            }
            else
            {
                cout<<0;
            }
        }
    }
    return 0;
}
