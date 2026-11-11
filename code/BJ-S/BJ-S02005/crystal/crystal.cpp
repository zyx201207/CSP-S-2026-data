#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
long long pjz=1,minx,pjs=1,cnt,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pjz+=a[i];
    }
    sort(a+1,a+n+1);
    pjz/=n;
    if(pjz>=a[1])
    {
        minx=pjz-a[1];
    }
    else
    {
        minx=a[1]-pjz;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=pjz)
        {
            if(a[i]-pjz<=minx)
            {
                minx=a[i]-pjz;
                pjs=i;
            }
        }
        else
        {
            if(pjz-a[i]<=minx)
            {
                minx=pjz-a[i];
                pjs=i;
            }
        }
    }
    for(int i=pjs;i>=1;i--)
    {
        if(cnt>m)
        {
            ans-=1;
            break;
        }
        cnt+=a[i]-a[pjs];
        ans++;
    }
    cout<<ans;
    return 0;
}
