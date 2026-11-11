#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,m,a[500005],cf[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cf[i]=a[i]-a[i-1];
    }
    long long k=a[n]-a[n-1];
    long long l=m*2;
    l=l/k;
    for(long long i=l;i>=1;i--)
    {
        if(i*(i-1)<=l)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
