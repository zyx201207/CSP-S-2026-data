#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,ans=2e9,b,e;
int W[500010],A[500010],dis[500010];
bool vis[500010];
vector<int> in[500010],t[500010],a[500010];
void dfs(int x,int sum,int line)
{
    if(sum>=ans)return;
    if(x==e)
    {
        ans=min(ans,sum);
        return;
    }
    for(auto i:a[x])
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i,sum,line);
            vis[i]=0;
        }
    }
    for(auto i:in[x])dfs(x,sum+t[line][x]+t[i][x],i);
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&m,&n,&d,&q);
    for(int i=1;i<=n;i++)scanf("%d",&W[i]);
    for(int i=1;i<=m;i++)
    {
        t[i].push_back(0);
        memset(A,0,sizeof A);
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            int T;
            scanf("%d %d",&A[j],&T);
            t[i].push_back(T);
            if(j>1)
            {
                a[A[j]].push_back(A[j-1]);
                a[A[j-1]].push_back(A[j]);
            }
            in[A[j]].push_back(i);
        }
    }
    while(q--)
    {
        scanf("%d %d",&b,&e);
        a[0].clear();
        a[0].push_back(b);
        dfs(0,0,0);
        printf("%d\n",ans+W[b]+W[e]);
    }
    return 0;
}
