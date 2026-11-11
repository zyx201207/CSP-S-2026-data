#include <bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005];
bool v[200005];
int n,m,ans;
int f(int cur,int o)
{
    if(cur>m)
    {
        ans=max(o,ans);
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            v[i]=1;
            f(cur+1,o&a[i]);
            v[i]=0;
        }
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
    }
    for(int i=1;i<=n;i++)
    {
        v[i]=1;
        f(2,a[i]);
        v[i]=0;
    }
    cout<<ans;
    return 0;
}
