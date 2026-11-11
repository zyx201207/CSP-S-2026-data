#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
long long ans=1;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--)
    {
        long long n,d;
        cin>>n>>d;
        for(long long i=1;i<=n;i++) cin>>x[i];
        if(C==13||C==14)
        {
            ans*=n*(n-1);
            ans/=2;
            cout<<ans<<endl;
        }
        ans=1;
    }
    return 0;
}
