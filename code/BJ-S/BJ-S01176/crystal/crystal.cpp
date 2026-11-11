#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans;
    long long a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
    {
        long long sum=m,anss=0;
        for(int j=i;j<=n;j++)
        {
            long long s=a[j]-a[j-1];
            if(sum>=2^s-1)
            {
                sum-=2^s-1;
                anss++;
            }
            else
            {
                break;
            }
        }
        ans=max(ans,anss);
    }
    cout<<ans;
    return 0;
}
