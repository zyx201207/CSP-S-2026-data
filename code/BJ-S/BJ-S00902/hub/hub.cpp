#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,deg[1000010],nd,dis[5010][5010],ans=2e9;
vector<int> a[1000010],tod[5];
bool ch[1000010],vis[1000010];
void dfs(int step)
{
    if(step>int(tod[1].size()))
    {
        int maxn=0;
        for(int i=1;i<n;i++)
        {
            if(ch[i]||i==nd)
            {
                int minn=2e9;
                for(int j=1;j<n;j++)
                {
                    if(ch[j]||j==nd)continue;
                    minn=min(minn,dis[i][j]);
                }
                maxn=max(maxn,minn);
            }
        }
        ans=min(ans,maxn);
        return;
    }
    ch[step]=1;
    dfs(step+1);
    ch[step]=0;
    dfs(step+1);
}
void init(int s,int x,int y,int cnt)
{
    vis[x]=1;
    dis[s][x]=cnt;
    for(auto i:a[x])
    {
        if(i==y||vis[i])continue;
        init(s,i,x,cnt+1);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--)
    {
        ans=2e9;
        scanf("%d %d",&n,&k);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
            deg[u]++,deg[v]++;
        }
        for(int i=1;i<n;i++){memset(vis,0,sizeof vis);init(i,i,0,0);}
        for(int i=1;i<n;i++)if(deg[i]<=2)tod[deg[i]].push_back(i);
        for(auto i:tod[2])
        {
            nd=i;
            dfs(0);
            nd=0;
            dfs(0);
        }
        printf("%d\n",ans);
    }
    return 0;
}
