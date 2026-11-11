#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll a[N],f[N];
bool vis[2112];
ll n,m;
ll wcr=0;
void dfs(ll i,ll sum,ll c)
{
    if(c>m)
    {
        wcr=max(wcr,sum);
        return ;
    }
    for(int j=1;j<=n;j++)
    {
        if(j==i || vis[j]) continue;
        vis[j]=1;
        dfs(j,sum&a[j],c+1);
        vis[j]=0;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=a[i];
    }
    if(n==m)
    {
        ll ans=a[1];
        for(int i=2;i<=n;i++) ans=ans&a[i];
        cout<<ans<<endl;
        return 0;
    }
    if(m==1)
    {
        ll mx=0;
        for(int i=1;i<=n;i++) mx=max(mx,a[i]);
        cout<<mx<<endl;
        return 0;
    }
    if(m==2)
    {
        for(int j=2;j<=m;j++)
        {
            for(int i=1;i<=n;i++)
            {
                ll cnt=0;
                for(int k=1;k<=n;k++)
                {
                    if(k==i) continue;
                    ll x=(f[k]&a[i]);
                    cnt=max(cnt,x);
                }
                f[i]=cnt;
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,f[i]);
        }
        cout<<ans<<endl;
        return 0;
    }
    if(n<=20)
    {
        for(int i=1;i<=n;i++)
        {
            vis[i]=1;
            dfs(i,a[i],1);
            vis[i]=0;
        }
        cout<<wcr<<endl;
        return 0;
    }
    sort(a+1,a+1+n,greater<int>());
    ll ans=a[1];
    for(int i=2;i<=m;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans<<endl;
    return 0;
}
