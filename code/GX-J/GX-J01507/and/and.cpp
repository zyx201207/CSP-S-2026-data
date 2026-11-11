#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,u=0;
    cin>>n>>m;
    long long a[n+1]={0},b[n+1]={0},sum[n+1]={0};
    for(long long i=1;i<=n;i++)
    {
         cin>>a[i];
    }
    sort(a,a+n+1);
    int o=1;
    for(int i=1;i<=n;i++)
    {
        o=1;
        while(1)
        {
            b[i]+=a[i]%2*o;
            o*=10;
            a[i]/=2;
            if(a[i]==1)
            {
                b[i]+=a[i]*o;
                break;
            }
        }
    }
    for(long long i=1;i<=n;i++)
    {
        u=0;
        o=1;
        int p=b[i+1];
        while(b[i])
        {
            u+=((b[i]%10)&(b[i+1]%10))*o;
            o*=10;
            b[i]/=10;
            b[i+1]/=10;
            if(b[i]<0||b[i+1]<0)
                break;
        }
        b[i+1]=p;
        int f=0;
        while(u)
        {
            sum[i]+=u%10*pow(2,f);
            f++;
            u/=10;
        }
    }
    long long ma=0;
    for(long long i=1;i<=n;i++)
    {
        if(sum[i]>ma)
        {
            ma=sum[i];
        }
    }
    cout<<ma;
    return 0;
}
