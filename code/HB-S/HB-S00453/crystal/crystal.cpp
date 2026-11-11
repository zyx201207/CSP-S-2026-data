#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,x;
ll a[500005],b[500005],c[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool f=true;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i]-a[i-1];
    }
    for(ll i=2;i<n;i++)
    {
        if(b[i]!=b[i+1])
        {
            f=false;
            break;
        }
    }
    if(f==true)
    {
        ll t;
        for(ll i=1;i<=n;i++)
        {
            ll sum=(1+i)*i/2;
            sum*=b[i];
            if(sum>m)
            {
                t=i;
                break;
            }
        }
        cout<<t;
        return 0;
    }
    sort(a+1,a+n+1);
    ll mid=(1+n)>>1;
    ll x=a[mid];
    k=m;
    for(ll i=1;i<=n;i++)
        c[i]=a[i];
    ll a1=0;
    for(ll i=mid;i>=1;i--)
    {
        ll y=x-c[i];
        if(y<=k)
        {
            k-=y;
            c[i]=x;
        }
        if(k<=0)    break;
    }
    for(ll i=1;i<=n;i++)
        if(c[i]==x) a1++;
    k=m;
    for(ll i=1;i<=n;i++)
        c[i]=a[i];
    ll a2=0;
    x=a[n];
    for(ll i=n;i>=mid;i--)
    {
        ll y=x-c[i];
        if(y<=k)
        {
            k-=y;
            c[i]=x;
        }
        if(k<=0)    break;
    }
    for(ll i=1;i<=n;i++)
        if(c[i]==x) a2++;
    cout<<max(a1,a2);
    return 0;
}
