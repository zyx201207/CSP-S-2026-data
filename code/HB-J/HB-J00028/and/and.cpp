#include<bits/stdc++.h>
using namespace std;
long long a[200020],sum[200020];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1)
    {
        int maxn=-1;
        for(int i=1;i<=n;i++)
            maxn=max(a[i],maxn);
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]&a[i];
        }
        cout<<sum[i];
        return 0;
    }
    if(m==n-1)
    {
        for(int i=2;i<=n;i++)
        {
            sum[i]=sum[i-1]&a[i];
        }
        for(int i=1;i<=n-1;i++)
        {
            sum[i]=sum[i-1]&a[i];
        }
        cout<<max(sum[n],sum[n-1]);
        return 0;
    }
    return 0;
}
