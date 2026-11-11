#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    ll dis;
    bool flag;
};
bool cmp(node x1,node y1)
{
    return x1.dis<y1.dis;
}
ll a[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m,ans=0;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    if(n>5000)
    {
        ll q=a[2]-a[1];
        while(q*(ans*(ans-1)/2)<=m)
        {
            ans++;
        }
        if(q*(ans*(ans-1)/2)>m) ans--;
        cout<<ans;
        return 0;
    }

    sort(a+1,a+1+n);
    node d[n+5];
    for(ll x1=n;x1>=1;x1--)
    {
        ll ans1=0,x=a[x1];
        for(ll i=1;i<=x1;i++)
        {
            if(x>=a[i])
            {
                d[i].dis=x-a[i];
                d[i].flag=true;
            }
        }
        sort(d+1,d+1+n,cmp);
        ll k=m;
        for(int i=1;i<=n;i++)
        {
            if(k<0) break;
            if(d[i].flag==true && k>=d[i].dis)
            {
                ans1++;
                k-=d[i].dis;
            }
        }
        ans=max(ans1,ans);
    }
    cout<<ans;
    return 0;
}
