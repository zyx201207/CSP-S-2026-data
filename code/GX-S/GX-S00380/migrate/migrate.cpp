#include<bits/stdc++.h>
using namespace std;
long long x[2000005],xn;
int c,t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        long long n,d;
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        xn=x[2]-x[1];
        long long k=d/xn;
        d=k;
        long long sum=0;
        for(int i=n;i>=d+2;i--)
        {
            sum++;
        }
        cout<<sum<<endl;
    }

    return 0;
}
