#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[200010],f[200010],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll w=2;
    for(int i=1;i<=30;i++)
    {
        w=w*2;
    }
    w--;
    cin>>n>>m;

    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    f[0]=w;
    if(n==m)
    {
        for(int i=1;i<=m;i++)
        {
            f[i]=f[i-1]&a[i];
        }
        cout<<f[m];
    }
    else if(m==n-1)
    {
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=n;i++)
            {
                if(i==j) continue;
                f[i]=f[i-1]&a[i];

            }
            ans=max(ans,f[m]);
        }
        cout<<ans;
    }
    else{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=min(m,i);j>=1;j--)
        {
            f[j]=max(f[j-1]&a[i],f[j]);
        }
    }
    cout<<f[m];
    }
    return 0;
}
