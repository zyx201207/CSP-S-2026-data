#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],jl[500005],ans;
bool b[25];
void dfs(ll lev)
{
    if(lev>n)
    {
        ll ls=0;ll ma=-3e12,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(b[i])
            {
                ma=max(ma,ll(i));
                cnt++;
            }
        }
        if(ma<1)
        {
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(b[i])
            {
                ls+=(a[ma]-a[i]);
            }
        }
        if(ls<=m)
        {
            ans=max(ans,cnt);
        }
        return;
    }
    dfs(lev+1);
    b[lev]=true;
    dfs(lev+1);
    b[lev]=false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1);
    cout<<ans;
    return 0;
}
