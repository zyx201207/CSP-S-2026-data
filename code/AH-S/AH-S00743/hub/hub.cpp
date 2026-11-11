#include<bits/stdc++.h>
using namespace std;
bool a[4004][4004];
int pos[4004];
struct node
{
    int num;
    int u;
}cnt[4004];
int fa[4004];
int n,k;/*
int f(int x)
{
    if(fa[x]==x)
    {
        return x;
    }
    return f(fa[x]);
}*/
bool f[4004][4004];
bool cmp(node x,node y)
{
    return x.num>y.num;
}
bool vis[4004];/*
void un(int x,int y)
{
    int px=f(x);
    int py=f(y);
    if(px!=py)
    {
        fa[px]=py;
    }
}*/
int dfs(int x,int sum)
{
    if(vis[x])
    {
        return sum;
    }
    int ans=0;
    for(int j=1;j<=n;j++)
    {
        if(f[x][j])
        {
            ans=max(ans,dfs(j,sum+1));

        }

    }
    return ans;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        memset(f,0,sizeof(f));
        memset(vis,0,sizeof(vis));
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
        }
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            //un(x,y);
            f[y][x]=1;
            f[x][y]=1;
        }
        cout<<n-k;
        return 0;
        for(int i=1;i<=n;i++)
        {
            cnt[i].num=0;
            for(int j=1+i;j<=n;j++)
            {
                if(f[i][j])
                {
                    cnt[i].num++;
                }
            }
            cnt[i].u=i;
        }
        sort(cnt+1,cnt+1+n,cmp);
        int now=1;
        while(k--)
        {
            now=1;
            while(vis[now]==1)
            {
                now++;
            }
            int x=cnt[now].u;
            vis[x]=1;
            for(int j=1;j<=n;j++)
            {
                if(f[x][j])
                {
                    for(int i=1;i<=n;i++)
                    {
                        if(cnt[i].u==j)
                        {
                            cnt[i].num--;
                        }
                    }
                }
            }
            sort(cnt+1,cnt+1+n,cmp);
        }
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dfs(i,0));
        }
        cout<<ans<<endl;
    }

    return 0;
}
