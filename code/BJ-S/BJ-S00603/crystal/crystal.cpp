#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long s[500010];
long long n,m;
long long ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag=true;
    bool f3=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1&&a[i]!=a[i-1])
        {
            flag=false;
        }
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])
        {
            f3=false;
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    if(flag==true)
    {
        cout<<n;
        return 0;
    }
    if(f3==true)
    {
        int wyc=0;
        for(int i=1;i<=n;i++)
        {
            if(1ll*(a[i]*i-s[i])<=m)
            {
                wyc++;
            }
        }
        cout<<wyc;
        return 0;
    }
    for(long long i=1;i<=n-ans;i++)
    {
        for(long long j=i;j<=n;j++)
        {
            long long num=(j-i+1)*a[j]-(s[j]-s[i-1]);
            if(num<=m)
            {
                ans=max(ans,(j-i+1));
            }
        }
    }
    cout<<ans;
    return 0;
}
