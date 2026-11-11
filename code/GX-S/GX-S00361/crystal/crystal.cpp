#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],sum=0,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(long long i=2;i<=n;i++)
    {
        long long o=i+1,mm=m,ans=0;
        while(--o)
        {
            if(a[i]-a[o]<=mm)
            {
                ans++;
                mm-=a[i]-a[o];
            }
        }
        sum=max(ans,sum);
    }
    cout<<sum;
    return 0;
}
