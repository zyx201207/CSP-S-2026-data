#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500010],d[500010],sum[500010];
ll n,m,ans=1;
bool check(ll s,ll t)
{
    ll i=s,j=t;
    ll su=sum[j]-(j-i+1)*d[j]-sum[i-1];

    if(su>m)
    {
     //   cout<<"false"<<'\n';
        return false;
    }
   // cout<<i<<' '<<j<<' '<<su<<'\n';
    ans=max(ans,j-i+1);
    return true;
}
void erfen(ll s)
{
    ll l=s,r=n,ls=s,mid=n;

    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(ls,mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    bool k=check(ls,mid);
}
bool fl=1,fg=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
        {
            fl=0;
        }
    }
    ll qq=a[2]-a[1];
    for(int i=3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=qq)
        {
            fg=0;
        }
    }
    if(fl==1)
    {
        ll qqq=0;
        for(ll i=1;i<=n;i++)
        {

            qqq+=i;
            if(qqq>m)
            {
                cout<<i;
                break;
            }
        }
    }
    else if(fg)
    {
        ll qqq=0;
        for(ll i=1;i<=n;i++)
        {

            qqq+=qq*i;
            if(qqq>m)
            {
                cout<<i;
                break;
            }
        }
    }
    else
    {


    sort(a,a+n+1);
    for(int i=1;i<=n;i++)
    {
        d[i]=a[n]-a[i];
        sum[i]=sum[i-1]+d[i];
       // cout<<i<<' '<<d[i]<<' '<<sum[i]<<'\n';
    }
    /*while(1)
    {
        if(sum[i]<=m)
        {
            cout<<i+1;
            break;
        }
        else
        {
            i--;
            sum[i]-=i*d[i+1];
        }
    }*/
    for(ll i=1;i<=n;i++)
    {
        /*for(ll j=i+1;j<=n;j++)
        {
            ll su=sum[j]-(j-i+1)*d[j]-sum[i-1];
           // cout<<i<<' '<<j<<' '<<su<<'\n';

            if(su>m)
            {
                break;
            }ans=max(ans,j-i+1);
        }*/
        erfen(i);
    }
    cout<<ans;
    }
    return 0;
}
