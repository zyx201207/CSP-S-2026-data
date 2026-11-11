#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],l=1,r,ans,len=1,mx=-1;
void rPush()
{
    r++;
    ans+=d[r]*len;
    len++;
}
void lPush()
{
    len--;
    ans-=(a[r]-a[l]);
    l++;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)d[i]=a[i]-a[i-1];
    for(r=1;r<=n;rPush())
    {
        while(ans>m)lPush();
        mx=max(mx,len);
    }
    cout<<mx;
    return 0;
}
