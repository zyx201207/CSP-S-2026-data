#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll a[N],n,m,maxx=-1e18,box[N],vis[N];
void dfs(ll step)
{
    if(step>m)
    {
        ll ans=box[1];
        for(int i=2;i<step;i++)ans=ans&box[i];
        maxx=max(maxx,ans);
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==1)continue;
        box[step]=a[i];
        vis[i]=1;
        dfs(step+1);
        vis[i]=0;

    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>a[i];
    if(n<=20)
    {
        dfs(1);
        cout<<maxx;
    }
    else if(m==n)
    {
        ll x=a[1];
        for(int i=1;i<=n;i++)x=x&a[i];
        cout<<x;
    }
    else if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    return 0;
    //Trick||Treat!
}
