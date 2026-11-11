#include<bits/stdc++.h>
using namespace std;
int maxand,a[200005],t,n,maxa;
bool vis[200005];

void dfs(int x,int cur)
{

    if(x>t)
    {
        maxand=max(cur,maxand);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
            continue;
        int xxx=cur&a[i];
        vis[i]=1;
        dfs(x+1,xxx);
        vis[i]=0;
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>t;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<21)
    {
        dfs(1,2147483647);
        cout<<maxand;
        return 0;
    }
    if(t==1)
    {
        int maxa=0;
        for(int i=1;i<=n;i++)
            maxa=max(maxa,a[i]);
        cout<<maxa;
        return 0;
    }
    if(t==n)
    {
        int x=0;
        for(int i=1;i<=n;i++)
            x&=a[i];
        cout<<x;
        return 0;
    }
    if(t==2)
    {
        int maxa=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                maxa=max(maxa,a[i]&a[j]);
            }
        cout<<maxa;
        return 0;
    }
    return 0;
}
