#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    unsigned long long m,n,ans=0;
    cin>>n>>m;
    for(unsigned long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(unsigned long long i=1;i<n;i++)
    {
        b[i]=a[i+1]-a[i];
    }
    for(unsigned long long i=1;i<n;i++)
    {
        b[i]*=i;
    }
    for(unsigned long long i=1;i<n;i++)
    {
        ans+=b[i];
        if(ans>m)
        {
            cout<<i;
            return 0;
        }
    }
}
