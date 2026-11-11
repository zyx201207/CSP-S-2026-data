#include <bits/stdc++.h>
using namespace std;
long long n,a[505000],ans;
unsigned long long m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool flag=1;
    unsigned long long t=a[2]-a[1];
    for(int i=3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=t)
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        unsigned long long s=n;
        for(int i=2;i<=n;i++)
        {
            unsigned long long c=(i-1)*i/2;
            c*=t;
            if(c>m)
            {
                s=i-1;
                break;
            }
        }
        cout<<s;
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        long long c=0;
        for(int j=i-1;j>=1;j--)
        {
            c+=a[i]-a[j];
            if(c>m)
            {
                break;
            }
            if(i-j+1>ans)
            {
                ans=i-j+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
