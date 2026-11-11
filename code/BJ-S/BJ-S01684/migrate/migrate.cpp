#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll c,t,flag,fposs;
ll n,k,mink;
ll a[N],vis[N];
map<ll,ll>mp;
void dfs(ll x,ll v,ll zd)
{
    if(x==zd)
    {
        mink=min(mink,v);
        mp[v]++;
        return ;
    }
    for(ll i=x+1;i<=zd;i++)
    {
        if(abs(a[x]-a[i])<=k&&vis[i]==1)
        {
            vis[i]=0;
            dfs(i,v+1,zd);
            vis[i]=1;
        }
    }
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        flag=0;
        cin>>n>>k;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(ll i=1;i<=n;i++)
        {
            if(a[i]-a[1]<=k&&a[n]-a[i]<=k)
            {
                flag=1;
                fposs=i;
                break;
            }
        }
        if(c>=11&&c<=12)
        {
            ll ge=k/(a[2]-a[1]);
            if(ge!=2)
            {
                cout<<"0\n";
            }
            else
            {
                cout<<n-3<<"\n";
            }
            continue;
        }
        else if(flag==1)
        {
            ll cnt1,cnt2,anss=0;
            cnt1=cnt2=0;
            for(ll i=fposs;i>=1;i--)
            {
                if(a[fposs+1]-a[i]>k)
                {
                    cnt1++;
                }
            }
            for(ll i=fposs-1;i<=n;i++)
            {
                if(a[i]-a[fposs-1]<=k&&a[i]-a[fposs-2]>k)
                {
                    cnt2++;
                }
            }
            anss+=cnt1*cnt2;
            cnt1=cnt2=0;
            for(ll i=fposs+1;i>=1;i--)
            {
                if(a[fposs+1]-a[i]<=k&&a[fposs+2]-a[i]>k)
                {
                    cnt1++;
                }
            }
            for(ll i=fposs;i<=n;i++)
            {
                if(a[i]-a[fposs-1]>k)
                {
                    cnt2++;
                }
            }
            anss+=cnt1*cnt2;
            cout<<anss<<"\n";
            continue;
        }
        ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=i+1;j<=n;j++)
            {
                mp.clear();
                for(ll we=1;we<=n;we++)
                {
                    vis[we]=1;
                }
                vis[i]=0;
                mink=INT_MAX;
                dfs(i,0,j);
                if(mp[mink]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

