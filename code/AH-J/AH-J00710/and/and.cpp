#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],maxx=-1,ans=-1,flaga=1,flagb=1;
int ejz(int x)
{
    long long t=1,cnt=30,fh=1,tt=1;
    for(int i=1;i<=30;i++)
    {
        t*=2;
    }
    while(x<t)
    {
        cnt--;
        t/=2;
    }
    for(int i=1;i<=cnt+1;i++)
    {
        fh*=2;
    }
    fh-=1;
    return fh;
}
void dfs(int dep,int v,int w)
{
    if(dep>n)
    {
        if(v==m)
        {
            if(w>ans)
            {
                ans=w;
            }
        }
    }
    else
    {
        dfs(dep+1,v,w);
        if(v+1<=m && (w&a[dep])>ans)
            dfs(dep+1,v+1,(w&a[dep]));
    }
}
signed main(void)
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(flaga==1 && ejz(a[i])!=a[i])
        {
            flaga=0;
        }
        maxx=max(maxx,a[i]);
    }
    if(flaga==1)
    {
        sort(a+1,a+1+n);
        ans=maxx;
        for(int i=n;i>=n-m+1;i--)
        {
            ans=(ans&a[i]);
        }
        cout<<ans<<endl;
        return 0;
    }
    dfs(1,0,ejz(maxx));
    cout<<ans<<endl;
    return 0;
}
