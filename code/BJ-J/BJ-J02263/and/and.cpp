#include<bits/stdc++.h>
using namespace std;
long long a[20000005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,sum=-1;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
         sum=max(sum,a[i]);
    }
    if(m==1)
    {
        cout<<sum;
        return 0;
    }
    if(m==2)
    {
        long long ans=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
                //cout<<ans<<endl;
            }
        }
        cout<<ans;
    }
    return 0;
}
