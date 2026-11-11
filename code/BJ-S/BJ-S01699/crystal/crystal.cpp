#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long a[1000010],s[1000010];
long long n,m,ans=0;
long long check(int x)
{
    int l=1,r=x,as=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[x]*(x-mid+1)-(s[x]-s[mid-1])<=m)
        {
            r=mid-1;
            as=mid;
        }
        else
        {
            l=mid+1;
        }

    }
    return x-as+1;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,check(i));
    }
    cout<<ans<<endl;
    return 0;
}
