#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],maxn;
bool vis[200005];
void dfs(int step)
{
    if(step>m)
    {
        int x;
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                if(!flag)
                {
                    x=a[i];
                    flag=true;
                }
                else

                {
                    x=x&a[i];
                }
            }
        }
        maxn=max(maxn,x);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(step+1);
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
        maxn=max(maxn,a[i]);
    }
    if(m==1)
    {
        cout<<maxn;
        return 0;
    }
    maxn=0;
    dfs(1);
    cout<<maxn;
    return 0;
}
