#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[200005],ans,vis[200005];
void dfs(int step,int cnt)
{
    if(step>n)
    {
        if(cnt!=m)
        {
            return;
        }
        int sum=0,f=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                if(f==0)
                {
                    sum=a[i];
                    f++;
                }
                sum=(sum&a[i]);
            }
        }
        ans=max(ans,sum);
        return;
    }
    if(cnt<m)
    {
        vis[step]=1;
        dfs(step+1,cnt+1);
        vis[step]=0;
    }
    dfs(step+1,cnt);
}
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
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
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,a[i]);
        }
        cout<<ans<<endl;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans<<endl;
    }
    else if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=(ans&a[i]);
        }
        cout<<ans<<endl;
    }
    else if(n<=20)
    {
        dfs(1,0);
        cout<<ans<<endl;
    }
    else
    {
        sort(a+1,a+n+1,cmp);
        cout<<a[m]<<endl;
    }
    return 0;
}