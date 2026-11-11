#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],vis[maxn];
int n,m,ma=-1;
void dfs(int x,int ans)
{
    if(x==m)
    {
        ma=max(ma,ans);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(x+1,ans&a[i]);
            vis[i]=0;
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
    if(m==1)
    {
        int ans=a[1];
        for(int i=1;i<=n;i++)
        {
            ans=max(a[i],ans);
        }
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        int maxa=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                max(maxa,a[i]&a[j]);
            }
        }
        cout<<maxa;
        return 0;
    }
    if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1)
    {
        int maxa=-1;
        for(int i=1;i<=n;i++)
        {
            int ans=(1<<20)-1;
            for(int j=1;j<=n;j++)
            {
                if(j!=i)
                {
                    ans&=a[j];
                }
            }
            maxa=max(maxa,ans);
        }
        cout<<maxa;
        return 0;
    }
    if(n<=20)
    {
        dfs(0,(1<<20)-1);
        cout<<ma;
        return 0;
    }
    return 0;
}
