#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using pi=pair<int,int>;
using vb=vector<bool>;
#define fi first
#define se second
vl a;
vb vis;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i,j;
    cin>>n>>m;
    a.resize(n+1);
    vis.resize(n+1,0);
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        vis[i]=1;
    }
    ll ans=0;
    for(i=30;i>=0;i--)
    {
        ll xx=(1LL<<i);
        ans+=xx;
        int cnt=0;
        for(j=1;j<=n;j++)
        {
            if(vis[j]&&(xx&a[j]))
            {
                cnt++;
            }
        }
        if(cnt<m) continue;
        for(j=1;j<=n;j++)
        {
            if(vis[j]&&((xx&a[j])==0))
            {
                vis[j]=0;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i])
        {
            ans&=a[i];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
/*
5 3
31 3 1 15 7
*/