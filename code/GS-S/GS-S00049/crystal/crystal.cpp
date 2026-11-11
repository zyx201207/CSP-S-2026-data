#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool fl=0;
    int f=0;
    long long sm=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1) f=a[i];
        if((a[i]-a[i-1])!=f) fl=1;

    }
    sort(a+1,a+1+n);
    long long ans=-1;
    for(int i=a[1];i<=a[n];i++)
    {
        long long cc=0,mm=m;
        for(int j=1;j<=n&&mm>=0;j++)
        {
            if(i>=a[j]&&mm>=(i-a[j]))
            {
                mm-=(i-a[j]);
                cc++;
            }

        }
        ans=max(ans,cc);
    }

    cout<<ans;
    return 0;
}
