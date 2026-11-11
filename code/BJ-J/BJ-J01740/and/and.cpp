#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,m;
ll a[N],ans;
ll p[N][50];
bool vis[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        vis[i]=true;
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        ll k=a[i],s=0;
        while(k>=1)
        {
            p[i][s]=k&1;
            k>>=1;
            s++;
        }
    }
    for(ll i=40;i>=0;i--)
    {
        ll ok=0;
        for(ll j=1;j<=n;j++)
        {
            if(vis[j]&&p[j][i]==1)
            {
                ok++;
            }
        }
        if(ok>=m)
        {
            for(ll j=1;j<=n;j++)
            {
                if(vis[j]&&p[j][i]==0)
                {
                    vis[j]=false;
                }
            }
            ll s=1;
            for(ll j=1;j<=i;j++)
            {
                s<<=1;
            }
            ans+=s;
        }
    }
    cout<<ans;
    return 0;
}
