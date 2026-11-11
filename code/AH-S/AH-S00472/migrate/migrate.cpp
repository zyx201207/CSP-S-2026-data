#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll maxn = 2e6+5;
ll c,T,n,m;
ll a[maxn];
ll ans;
ll b[maxn];
ll cnt[maxn];
void check(ll l,ll r)
{
    //枚举后检查是否合法&&cnt[]++
    ll j=l,sum=0;
    for (ll i=l+1;i<=r-1;i++)
    {
        if (b[i]) 
        {
            if (a[i]-a[j]<=m)
            {
                j=i;
                sum++;
            }
            else return ;
        }
    }
    if (a[r]-a[j]<=m)
    {
        cnt[sum]++;
    }
}

void dfs(ll dep,ll l,ll r)
{
    //枚举中间的选择
    if (dep>r-l-1)
    {
        // for (ll i=l+1;i<=r-1;i++)
        // {
        //     cout<<b[i];
        // }
        // cout<<" ";
        check(l,r);
        return ;
    }

    b[l+dep]=1;
    dfs(dep+1,l,r);
    b[l+dep]=0;
    dfs(dep+1,l,r);
}

void calc()
{ 
    //枚举l r
    for (ll i=1;i<n-2;i++)
    {
        for (ll j=i+3;j<=n;j++)
        {
            memset(cnt,0,sizeof(cnt));
            dfs(1,i,j);
            // prllf("l=%d,r=%d ",i,j);
            for (ll k=0;k<=j-i;k++)
            {
                // cout<<i<<" "<<cnt[i]<<" ";
                if (cnt[k]) 
                {
                    if (cnt[k]==2) 
                    {
                        // prllf("l=%d,r=%d ",i,j);
                        ans++;
                    }
                    break ;
                }
            }  
            // cout<<endl;
    }
}
}

int main ()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>c>>T;
    while (T--)
    {
        ans=0;
        cin>>n>>m;
        for (ll i=1;i<=n;i++)
        {
            cin>>a[i];

        }
        calc();
        cout<<ans<<"\n";
    }
    return 0;
}