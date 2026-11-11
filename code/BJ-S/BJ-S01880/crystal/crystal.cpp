#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans,a[500005],suba=1,subb=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)suba=0;
        /*
        a[i+n].v=a[i].v+m;
        a[i+n].f=1;
        */
    }
    if(suba)
    {
        ans=1;
        for(int i=n-1;i>=1;i--)
        {
            //cout<<i;
            if(n-i<=m)
            {
                ans++;
                m-=n-i;
            }
            //else break;
        }
        cout<<ans;
        return 0;
    }
    ll d=a[2]-a[1];
    for(int i=3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=d)subb=0;
    }
    if(subb)
    {
        sort(a+1,a+n+1);
        ans=1;
        for(int i=n-1;i>=1;i--)
        {
            if(a[n]-a[i]<=m)
            {
                ans++;
                m-=(a[n]-a[i]);
            }
            else break;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        ll cnt=1,tmp=m;
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]-a[j]<=tmp)
            {
                tmp-=(a[i]-a[j]);
                cnt++;
            }
            else
            {
                break;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
