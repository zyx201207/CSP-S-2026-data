#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,x[2000006];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(long long i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(long long j=1;j<=n;j++)
        {
            cin>>x[i];

        }
        for(long long j=1;j<=n;j++)
        {
            if(x[j+1]-x[j]>d||d>x[n])
            {
                cout<<0<<endl;
            }
        }
    }
    return 0;
}
