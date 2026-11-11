#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main()
{
    freopen("migrate.in",r,stdin);
    freopen("migrate.out",w,stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(c==11||c==12)
        {
            if(x[2]-x[1]<=d)
            {
                cout<<(n-1)*(x[2]-x[1])/d+1<<endl;
            }
        }
        if(c==13||c==14)
        {
            if(d>=x[n]-x[1])
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<2<<endl;
            }
        }
    }
    return 0;
}
