#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ans=1;
    long long mid=0;
    if(n%2==1)
    {
        mid=n/2+1;
    }
    else mid=n/2;
    for(long long k=mid+1;k<=n;k++)
    {
        if(a[k]==a[mid])
        {
            ans++;
        }
    }
    for(long long i=mid-1;i>=1;i--)
    {
        m-=a[mid]-a[i];
        if(m<0)break;
        ans+=1;
    }
    cout<<ans;
    return 0;
}
